#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/device.h> 	//class_create
#define MEMDEV_MAJOR 254
#define MEMDEV_NR_DEVS 2
#define MEMDEV_SIZE 4096

static struct class *firstdrv_class;
static struct device *firstdrv_device;

struct mem_dev                                     
{                                                        
  char *data;                      
  unsigned long size; 
  wait_queue_head_t inq;  
};

static int mem_major = 0;
bool have_data = false; /*表明设备有足够数据可供读*/
module_param(mem_major, int, S_IRUGO);/*用户态用main()传递命令行参数，内核模块用module_param()，S_IRUGO表示
可以被所有人读取，但不可修改*/
struct mem_dev *mem_devp; /*设备结构体指针*/
struct cdev cdev;

int mem_open(struct inode *inode, struct file *filp)
{
    struct mem_dev *dev;
    
    /*获取次设备号*/
    int num = MINOR(inode->i_rdev);

    if (num >= MEMDEV_NR_DEVS) 
            return -ENODEV;
    dev = &mem_devp[num];
    
    /*将设备描述结构指针赋值给文件私有数据指针*/
    filp->private_data = dev;
    
    return 0; 
}

int mem_release(struct inode *inode, struct file *filp)
{
  return 0;
}

static ssize_t mem_read(struct file *filp, char __user *buf, size_t size, loff_t *ppos)
{
  unsigned long p =  *ppos;
  unsigned int count = size;
  int ret = 0;
  struct mem_dev *dev = filp->private_data; /*获得设备结构体指针*/

  /*判断读位置是否有效*/
  if (p >= MEMDEV_SIZE)
    return 0;
  if (count > MEMDEV_SIZE - p)
    count = MEMDEV_SIZE - p;
    
  while (!have_data) /* 没有数据可读*/
  {
        if (filp->f_flags & O_NONBLOCK)
            return -EAGAIN;
    
    wait_event_interruptible(dev->inq,have_data);
  }

  /*读数据到用户空间*/
  if (copy_to_user(buf, (void*)(dev->data + p), count))
  {
    ret =  - EFAULT;
  }
  else
  {
    *ppos += count;
    ret = count;
   
    printk(KERN_INFO "read %d bytes(s) from %d\n", count, p);
  }
  
  have_data = false; /* 不再有数据可读 */
  /* 唤醒写进程 */
  return ret;
}

static ssize_t mem_write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos)
{
  unsigned long p =  *ppos;
  unsigned int count = size;
  int ret = 0;
  struct mem_dev *dev = filp->private_data; /*获得设备结构体指针*/
  
  /*分析和获取有效的写长度*/
  if (p >= MEMDEV_SIZE)
    return 0;
  if (count > MEMDEV_SIZE - p)
    count = MEMDEV_SIZE - p;

  /*从用户空间写入数据*/
  if (copy_from_user(dev->data + p, buf, count))
    ret =  - EFAULT;
  else
  {
    *ppos += count;
    ret = count;
    
    printk(KERN_INFO "written %d bytes(s) from %d\n", count, p);
  }
  
  have_data = true; /* 有新的数据可读 */
    
    /* 唤醒读进程 */
    wake_up(&(dev->inq));

  return ret;
}

static loff_t mem_llseek(struct file *filp, loff_t offset, int whence)
{ 
    loff_t newpos;

    switch(whence) {
      case 0: /* SEEK_SET */
        newpos = offset;
        break;

      case 1: /* SEEK_CUR */
        newpos = filp->f_pos + offset;
        break;

      case 2: /* SEEK_END */
        newpos = MEMDEV_SIZE -1 + offset;
        break;

      default: /* can't happen */
        return -EINVAL;
    }
    if ((newpos<0) || (newpos>MEMDEV_SIZE))
        return -EINVAL;
        
    filp->f_pos = newpos;
    return newpos;

}

unsigned int mem_poll(struct file *filp, poll_table *wait)
{
    struct mem_dev  *dev = filp->private_data; 
    unsigned int mask = 0;
    
   /*将等待队列添加到poll_table */
    poll_wait(filp, &dev->inq,  wait);
 
    
    if (have_data)         mask |= POLLIN | POLLRDNORM;  /* readable */

    return mask;
}

static const struct file_operations mem_fops =
{
  .owner = THIS_MODULE,
  .llseek = mem_llseek,
  .read = mem_read,
  .write = mem_write,
  .open = mem_open,
  .release = mem_release,
  .poll = mem_poll,
};

static int memdev_init(void)
{
  int result;
  int i;

  dev_t devno = MKDEV(mem_major, 0);

  /* 静态申请设备号*/
  if (mem_major)
    result = register_chrdev_region(devno, 2, "memdev");
  else  /* 动态分配设备号 */
  {
    result = alloc_chrdev_region(&devno, 0, 2, "memdev");/*0为起始次设备号，2为次设备号的数量*/
    mem_major = MAJOR(devno);
  }  
  
  if (result < 0)
    return result;

  /*初始化cdev结构*/
  cdev_init(&cdev, &mem_fops);
  cdev.owner = THIS_MODULE;
  cdev.ops = &mem_fops;
  
  /* 注册字符设备 */
  cdev_add(&cdev, MKDEV(mem_major, 0), MEMDEV_NR_DEVS);
   
  /* 为设备描述结构分配内存*/
  mem_devp = kmalloc(MEMDEV_NR_DEVS * sizeof(struct mem_dev), GFP_KERNEL);
  if (!mem_devp)    /*申请失败*/
  {
    result =  - ENOMEM;
    goto fail_malloc;
  }
  memset(mem_devp, 0, sizeof(struct mem_dev));
  
  /*为设备分配内存*/
  for (i=0; i < MEMDEV_NR_DEVS; i++) 
  {
        mem_devp[i].size = MEMDEV_SIZE;
        mem_devp[i].data = kmalloc(MEMDEV_SIZE, GFP_KERNEL);
        memset(mem_devp[i].data, 0, MEMDEV_SIZE);
  
      /*初始化等待队列*/
     init_waitqueue_head(&(mem_devp[i].inq));
     //init_waitqueue_head(&(mem_devp[i].outq));
  }
  firstdrv_class = class_create(THIS_MODULE, "firstdrv");
  firstdrv_device = device_create(firstdrv_class, NULL, MKDEV(mem_major, 0), NULL, "memdev0");
   
  return 0;

  fail_malloc: 
  unregister_chrdev_region(devno, 1);
  
  return result;
}

static void memdev_exit(void)
{
  cdev_del(&cdev);   /*注销设备*/
  kfree(mem_devp);     /*释放设备结构体内存*/
  unregister_chrdev_region(MKDEV(mem_major, 0), 2); /*释放设备号*/
  device_unregister(firstdrv_device);  //卸载类下的设备
  class_destroy(firstdrv_class);		//卸载类
}

MODULE_AUTHOR("David Xie");
MODULE_LICENSE("GPL");

module_init(memdev_init);
module_exit(memdev_exit);

