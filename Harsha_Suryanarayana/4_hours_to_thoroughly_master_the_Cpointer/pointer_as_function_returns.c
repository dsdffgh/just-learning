#include <stdio.h>
#include <stdlib.h>

//ָ����Ϊ��������
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
    //����д��������ģ���Ϊc��Add��������ͷ���https://www.bilibili.com/video/BV1bo4y1Z7xf/?p=15&vd_source=8f1d3288d9e71805521fa68fb84f9007
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
    printf("Address = %d\n", ptr);//ע�⵽linux�е�ַ�ǲ���ģ��Ȳ���Ϊɶ
}
#endif
