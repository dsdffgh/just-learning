#include <fcntl.h>  
#include <stdio.h>  
#include <poll.h> 
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
int main(int argc, char **argv){  
    int fd;  
    unsigned char key_val;
    //unsigned char pin; 
    int ret;  
    int led_no;
    int on;
    int Led_fd;

    struct pollfd fds[1];  

    fd = open("/dev/buttons", O_RDWR);  
    if (fd < 0){  
        printf("can't open!\n");  
    }  
            led_fd = open("/dev/s5pv210_led", 0);
            if (led_fd < 0) {
                led_fd = open("/dev/s5pv210_led", 0);
            }
            if (led_fd < 0) {
                perror("open device leds");
                exit(1);
            }

    fds[0].fd     = fd;  
    fds[0].events = POLLIN;  
    while (1){  
        ret = poll(fds, 1, 5000);  /* 调用 poll 函数来监听文件描述符的可读事件，等待最多 5000 毫秒（5 秒）。如果在超时时间内没有发生事件，poll 函数返回 0；如果有事件发生，poll 函数返回大于 0 的值。*/
        if (ret == 0){  
            printf("time out\n");  
        }  
        else{  
            on = !(!ret);
            read(fd, &key_val, 1);  
            led_no = key_val;
            printf("key_val = 0x%x\n", key_val); 
        }  
    }  


    return 0;  
}  
