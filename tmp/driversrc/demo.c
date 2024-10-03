/**************************************************************
	demo.c
	linux driver example for up-tech270 platform 
	It can be compiled for x86 PC
	author: wbn
	date:   2006-05-31
	derive from zou jian-guo's driver exp.
***************************************************************/


//#define CONFIG_DEVFS_FS
#ifdef MODULE
//#include <linux/config.h>
#include <linux/module.h>

#ifdef CONFIG_DEVFS_FS
#include <linux/devfs_fs_kernel.h>
#endif


#include <linux/init.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>   /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/poll.h>    /* COPY_TO_USER */
#include <asm/system.h>     /* cli(), *_flags */

#define DEVICE_NAME	"testdemo"
#define DEMORAW_MINOR	1
#define DEMO_Devfs_path	"demo/0"

static int demoMajor = 0;
static int MAX_BUF_LEN=1024;
static char drv_buf[1024];
static int WRI_LENGTH=0;

/*************************************************************************************/
/*逆序排列缓冲区数据*/
static void do_write(void)
{

	int i;
	int len = WRI_LENGTH;
	int mid = len>>1;
	char tmp;
	for(i = 0; i < mid; i++,len--){
		tmp = drv_buf[len-1];
		drv_buf[len-1] = drv_buf[i];
		drv_buf[i] = tmp;
	}
}
/*************************************************************************************/
static ssize_t  demo_write(struct file *file, const char __user *buffer, size_t count, loff_t * ppos)
{ 
	if(count > MAX_BUF_LEN)count = MAX_BUF_LEN;
	copy_from_user(drv_buf , buffer, count);
	WRI_LENGTH = count;
//	printk("user write data to driver\n");
	do_write();	
	return count;
}
/*************************************************************************************/
static ssize_t  demo_read(struct file *filp, char __user *buffer, size_t count, loff_t *ppos)
{
	if(count > MAX_BUF_LEN)
		count=MAX_BUF_LEN;
	copy_to_user(buffer, drv_buf,count);
//	printk("user read data from driver\n");
	return count;
}
/*************************************************************************************/
static int demo_ioctl(struct inode *inode, struct file *filp, 
                 unsigned int cmd, unsigned long arg)
{
//	printk("ioctl runing\n");
	switch(cmd){
		case 1:printk("runing command 1 \n");break;
		case 2:printk("runing command 2 \n");break;
		default:
			printk("error cmd number\n");break;
	}
	return 0;
}
/*************************************************************************************/
static int demo_open(struct inode *inode, struct file *filp)
{
//	MOD_INC_USE_COUNT;
	printk("device open sucess!\n");
	return 0;
}
/*************************************************************************************/
static int  demo_release(struct inode *inode, struct file *filp)
{
//	MOD_DEC_USE_COUNT;
	printk("device release\n");
	return 0;
}

/*************************************************************************************/
static struct file_operations pxa270_fops = {
	owner:	THIS_MODULE,
	write:	demo_write,	
	read:	demo_read,	
	ioctl:	demo_ioctl,
	open:	demo_open,
	release:	demo_release,
};
/*************************************************************************************/

static int __init demo_init(void)
{
 int ret;
 	ret = register_chrdev(0, DEVICE_NAME, &pxa270_fops);
	if (ret < 0) {
		printk(DEVICE_NAME " can't get major number\n");
		return ret;
	}
	demoMajor=ret;

	#ifdef CONFIG_DEVFS_FS
	devfs_mk_cdev(MKDEV(demoMajor, DEMORAW_MINOR), 
			S_IFCHR|S_IRUSR|S_IWUSR|S_IRGRP, DEMO_Devfs_path);
	#endif
	return 0;
}

/*************************************************************************************/
#ifdef MODULE
void __exit  demo_exit(void)
{
#ifdef CONFIG_DEVFS_FS	
	devfs_remove(DEMO_Devfs_path);
#endif
	unregister_chrdev(demoMajor, DEVICE_NAME);
}
module_exit(demo_exit);
#endif

/*************************************************************************************/
module_init(demo_init);

MODULE_LICENSE("Dual BSD/GPL");
#endif		// MODULE
