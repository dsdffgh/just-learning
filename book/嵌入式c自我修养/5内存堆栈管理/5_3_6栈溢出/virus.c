/* ************************************************************************
> File Name:     virus.c
# Author:       Theonesssssssss
# mail:         whyunotdo@qq.com
> Created Time:  Mon Oct 16 20:31:02 2023
> Description:   
 ************************************************************************/

#include<stdio.h>

void shellcode()
{
   printf("virus run success");
}

void f()
{
    int a[4];
    a[8] = shellcode;
}

int main()
{
    f();
    printf("hello!\n");
    return 0;
}
