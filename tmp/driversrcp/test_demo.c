#include <stdio.h>  
int main()  
{  
 FILE *fp0 = NULL;  
 char Buf[4096];  
   
 /*初始化Buf*/  
 strcpy(Buf,"Mem is char dev!");  
 printf("BUF: %s\n",Buf);  
   
 /*打开设备文件*/  
 fp0 = fopen("/dev/memdev0","r+");  
 if (fp0 == NULL)  
 {  
  printf("Open Memdev0 Error!\n");  
  return -1;  
 }  
   
 /*写入设备*/  
 //fwrite(Buf, sizeof(Buf), 1, fp0);  
   
 /*重新定位文件位置（思考没有该指令，会有何后果)*/  
 //fseek(fp0,0,SEEK_SET);//调用mem_llseek（）定位，使文件指针移回到开始的位置，方便读  
   
 /*清除Buf*/  
 strcpy(Buf,"Buf is NULL!");//覆盖以前的值，以防读不出来的时候无法判断  
 printf("BUF: %s\n",Buf);  
   
   
 /*读出设备*/  
 fread(Buf, sizeof(Buf), 1, fp0);  
   
 /*检测结果*/  
 printf("BUF: %s\n",Buf);  
   
 return 0;   
}  
