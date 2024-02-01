#include <stdio.h>
#include <stdlib.h>

//指针作为函数返回
#if 1
void PrintHello()
{
    printf("Hello!\n");
}

int* Add(int *a, int *b)
{
    int c = (*a) + (*b);
    //return c;
    return &c; //wanning:function returns address of local variable [-Wreturn-local-addr]
    //这样写是有问题的，因为c在Add结束后就释放了https://www.bilibili.com/video/BV1bo4y1Z7xf/?p=15&vd_source=8f1d3288d9e71805521fa68fb84f9007
}

int main()
{
    int x = 2, y = 4;
    int *ptr = Add(&x, &y);
    printf("Sum = %d\n", *ptr);
}
#endif

#if 0
void PrintHello()
{
    printf("Hello!\n");
}

int *Add(int *a, int *b)
{
    int *c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
}

int main()
{
    int x = 2, y = 4;
    int *ptr = Add(&x, &y);
    PrintHello();
    printf("Sum = %d\n", *ptr);
    printf("Address = %d\n", ptr);//注意到linux中地址是不变的，先不管为啥
}
#endif
