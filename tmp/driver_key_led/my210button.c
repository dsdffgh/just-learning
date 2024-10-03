#include <linux/types.h>  
#include <linux/module.h>  
#include <linux/cdev.h>  
#include <linux/fs.h>  
#include <linux/device.h>  
#include <linux/gpio.h>  
#include <linux/irq.h>  
#include <linux/interrupt.h>  
#include <linux/sched.h>   
#include <linux/wait.h>  
#include <linux/uaccess.h>  
#include <linux/poll.h>
#include <linux/init.h>    
#include <linux/module.h>   
  
#include <linux/cdev.h>  
#include <linux/kernel.h>    
#include <linux/fs.h>    
#include <linux/delay.h>    
#include <asm/irq.h>    
#include <mach/regs-gpio.h>    
#include <mach/hardware.h>    
#include <linux/device.h>    
#include <linux/gpio.h>    
  
  
#define DEVICE_NAME "s5pv210_led"  
#define DEVICE_COUNT 1  
#define SP5V210_LED_MAJOR 0  
#define SP5V210_LED_MINOR 234  
  
#define LED_OFF      0  
#define LED_ON       1  
#define ALL_LED_OFF  3  
#define ALL_LED_ON   4  
  
  
static int major = SP5V210_LED_MAJOR;  
static int minor = SP5V210_LED_MINOR;  
static dev_t dev_number;  
  
static struct class *led_class = NULL;  
  
static unsigned long led_table []=  
{  
    S5PV210_GPJ2(0),  
    S5PV210_GPJ2(1),  
    S5PV210_GPJ2(2),  
    S5PV210_GPJ2(3),  
};  
static dev_t devno;  
static struct cdev cdev;  
static struct class* buttons_class;  
static struct device* buttons_device;  
  
static wait_queue_head_t button_waitq;  
  
static volatile int pressed = 0;  
static unsigned char key_val;  
unsigned char pin_val;
struct key_desc{  
    unsigned int  pin;  
    unsigned char value;  
};  
  
static struct key_desc key_descs[8] = {  
    [0] = {  
        .pin = S5PV210_GPH0(0),  
        .value = 0x00,  
    },  
  
    [1] = {  
        .pin = S5PV210_GPH0(1),  
        .value = 0x01,  
    },  
  
    [2] = {  
        .pin = S5PV210_GPH0(2),  
        .value = 0x02,  
    },  
  
    [3] = {  
        .pin = S5PV210_GPH0(3),  
        .value = 0x03,  
    },  
  
};  
  
static irqreturn_t buttons_irq(int irq, void *dev_id){  
    volatile struct key_desc *key = (volatile struct key_desc *)dev_id;
    if(gpio_get_value(key->pin)){  
        //key_val = key->value|0x80;  
       key_val =gpio_get_value(key->pin);
    }  
    else{  
        key_val = gpio_get_value(key->pin);  
    }   
    pressed = 1;  
    wake_up_interruptible(&button_waitq);
    int led_on = !gpio_get_value(led_table[key_val]);
    gpio_set_value(led_table[key_val],led_on);  
  
  
    return IRQ_RETVAL(IRQ_HANDLED);  
}  
  
static int buttons_open(struct inode *inode, struct file *file){  
    int ret;  
  
    ret = request_irq(IRQ_EINT(16),   buttons_irq, IRQ_TYPE_EDGE_BOTH, "key1", &key_descs[0]);  
    if(ret)  
        return ret;  
    ret = request_irq(IRQ_EINT(17),   buttons_irq, IRQ_TYPE_EDGE_BOTH, "key2", &key_descs[1]);  
    if(ret)  
        return ret;  
    ret = request_irq(IRQ_EINT(18),   buttons_irq, IRQ_TYPE_EDGE_BOTH, "key3", &key_descs[2]);  
    if(ret)  
        return ret;  
    ret = request_irq(IRQ_EINT(19),   buttons_irq, IRQ_TYPE_EDGE_BOTH, "key4", &key_descs[3]);  
    if(ret)  
        return ret;    
    return 0;  
}  

static unsigned buttons_poll(struct file *file, poll_table *wait){  
    unsigned int mask = 0;  
    poll_wait(file, &button_waitq, wait);  
  
    if (pressed)  
        mask |= POLLIN | POLLRDNORM;  
  
    return mask;  
}  
  
static ssize_t buttons_read(struct file * file, char __user *data, size_t count, loff_t *loff){  
    if(count != 1){  
        printk(KERN_ERR "The driver can only give one key value once!\n");  
        return -ENOMEM;  
    }  
  
    wait_event_interruptible(button_waitq, pressed);  
    pressed = 0;  
  
    if(copy_to_user(data, &key_val, 1)){  
        printk(KERN_ERR "The driver can not copy the data to user area!\n");  
        return -ENOMEM;  
    }  
      
    return 0;  
}  
  
static int buttons_close(struct inode *inode, struct file *file){  
    free_irq(IRQ_EINT(16),  &key_descs[0]);  
    free_irq(IRQ_EINT(17),  &key_descs[1]);    
    free_irq(IRQ_EINT(18),  &key_descs[2]);  
    free_irq(IRQ_EINT(19),  &key_descs[3]);  
    return 0;  
}  
  
struct file_operations buttons_ops = {  
    .open    = buttons_open,  
    .read    = buttons_read,  
    .release = buttons_close,  
    .poll    = buttons_poll,
};  
   
static long s5pv210_led_ioctl(struct file *filp, unsigned int cmd,  
        unsigned long arg)  
{  
    int i;  
    if (arg > 4)  
    {  
        return -EINVAL;  
    }  
    switch(cmd)  
    {  
        case LED_OFF:  
            {  
                gpio_set_value(led_table[arg],1);  
                printk("LED_OFF\n");  
            }     
            break;  
  
        case LED_ON:  
            {  
                gpio_set_value(led_table[arg],0);  
                printk("LED_ON\n");  
            }             
            break;  
          
        case ALL_LED_OFF:  
            for (i = 0; i < 4; i++)        
            {  
                gpio_set_value(led_table[i],1);  
                printk("ALL_LED_OFF\n");  
            }                 
            break;  
  
        case ALL_LED_ON:  
            for (i = 0; i < 4; i++)  
            {  
                gpio_set_value(led_table[i],0);  
                printk("ALL_LED_ON\n");  
            }                 
            break;  
          
        default:  
            {  
                printk("ONNE\n");  
                return -EINVAL;   
            }  
              
    }  
}   
    
static struct file_operations dev_fops =  
{ .owner = THIS_MODULE, .unlocked_ioctl = s5pv210_led_ioctl};  
static struct cdev leds_cdev;  

  static int led_create_device(void)  
{  
    int ret = 0;  
    int err = 0;  
  
    cdev_init(&leds_cdev, &dev_fops);  
    leds_cdev.owner = THIS_MODULE;  
  
    err = alloc_chrdev_region(&leds_cdev.dev, 10, DEVICE_COUNT,DEVICE_NAME);  
    if (err < 0)  
    {  
        printk(KERN_WARNING "alloc_chrdev_region() failed\n");  
        return err;  
    }  
    major = MAJOR(leds_cdev.dev);  
    minor = MINOR(leds_cdev.dev);  
    dev_number = leds_cdev.dev;  
  
    ret = cdev_add(&leds_cdev,dev_number,DEVICE_COUNT);  
    led_class = class_create(THIS_MODULE,DEVICE_NAME);  
    device_create(led_class,NULL,dev_number,NULL,DEVICE_NAME);  
  
    return ret;  
}  
  
int buttons_init(void){  
    int ret;  
    ret = led_create_device();  
  
    gpio_direction_output (S5PV210_GPJ2(0), 1);  
    gpio_direction_output (S5PV210_GPJ2(1), 1);  
    gpio_direction_output (S5PV210_GPJ2(2), 1);  
    gpio_direction_output (S5PV210_GPJ2(3), 1);  
  
    gpio_set_value (S5PV210_GPJ2(0), 0);  
    gpio_set_value (S5PV210_GPJ2(1), 0);  
    gpio_set_value (S5PV210_GPJ2(2), 0);  
    gpio_set_value (S5PV210_GPJ2(3), 0);  
  
    printk(DEVICE_NAME" LED \tinitialized\n");  
  
    cdev_init(&cdev, &buttons_ops);  
    cdev.owner = THIS_MODULE;  
  
    ret = alloc_chrdev_region(&devno, 0, 1, "buttons");  
    if(ret){  
        printk(KERN_ERR "alloc char device region faild!\n");  
        return ret;  
    }  
  
    ret = cdev_add(&cdev, devno, 1);  
    if(ret){  
        printk(KERN_ERR "add char device faild!\n");  
        goto add_error;  
    }  
  
    buttons_class = class_create(THIS_MODULE, "buttonsdrv");  
    if(IS_ERR(buttons_class)){  
        printk(KERN_ERR "create class error!\n");  
        goto class_error;  
    }  
  
    buttons_device = device_create(buttons_class, NULL, devno, NULL, "buttons");  
    if(IS_ERR(buttons_device)){  
        printk(KERN_ERR "create buttons device error!\n");  
        goto device_error;  
    }  
  
    init_waitqueue_head(&button_waitq);  
  
    return 0;  
  
device_error:  
    class_destroy(buttons_class);  
class_error:  
    cdev_del(&cdev);  
add_error:  
    unregister_chrdev_region(devno,1);  
  
    return -ENODEV;  
}  
    
static void led_destroy_device(void)  
{  
    device_destroy(led_class,dev_number);  
    if (led_class)  
        class_destroy(led_class);  
    unregister_chrdev_region(dev_number,DEVICE_COUNT);  
    return;  
}  

void buttons_exit(void){  
	led_destroy_device();  
    printk(DEVICE_NAME" LED \texit!\n");  
    device_destroy(buttons_class, devno);  
    class_destroy(buttons_class);  
    cdev_del(&cdev);  
    unregister_chrdev_region(devno, 1);  
}  
  
module_init(buttons_init);  
module_exit(buttons_exit);  
MODULE_LICENSE("GPL");  
