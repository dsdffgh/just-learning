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
  
static int s5pv210_led_init(void)  
{  
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
  
    printk(DEVICE_NAME"\tinitialized\n");  
  
    return ret;  
}  
  
static void led_destroy_device(void)  
{  
    device_destroy(led_class,dev_number);  
    if (led_class)  
        class_destroy(led_class);  
    unregister_chrdev_region(dev_number,DEVICE_COUNT);  
    return;  
}  
  
static void s5pv210_led_exit(void)  
{  
    led_destroy_device();  
    printk(DEVICE_NAME"\texit!\n");  
}  
  
module_init(s5pv210_led_init);  
module_exit(s5pv210_led_exit);  
MODULE_LICENSE("GPL");  
MODULE_AUTHOR("Fedomn");  
