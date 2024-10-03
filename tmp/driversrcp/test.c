#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

int main()
{
    int fd;
    fd_set rds;
    int ret;
    char Buf[128];
    struct timeval    tv;
    tv.tv_sec = tv.tv_usec = 10;
    /*初始化Buf*/
    strcpy(Buf,"memdev is char dev!");
    printf("BUF: %s\n",Buf);
    
    /*打开设备文件*/
    fd = open("/dev/memdev0",O_RDWR);
    
    FD_ZERO(&rds);
    FD_SET(fd, &rds);

    /*清除Buf*/
    strcpy(Buf,"Buf is NULL!");
    printf("Read BUF1: %s\n",Buf);

    ret = select(fd + 1, &rds, NULL, NULL, &tv);
    if (ret < 0) 
    {
        printf("select error!\n");
        exit(1);
    }
    int number=0;
    if (FD_ISSET(fd, &rds)) 
        number = read(fd, Buf, sizeof(Buf));   
           
    
    /*检测结果*/
    printf("Read BUF2: %s,%d\n",Buf,number);
    
    close(fd);
    
    return 0;    
}
