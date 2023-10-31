#include <stdio.h>
#if 1

int Add(int a, int b)
{
    return a+b;
}
void PrintHello(char* name)
{
    printf("Hello %s\n",name);
}
int main()
{
    int c, d;
    int (*p)(int, int);//int *P(int, int)则表示返回一个整形指针的函数:  int* P(int, int)
    p = &Add;
    c = (*p)(2, 3);
    printf("%d\n",c);
//下面这种也可以
    int (*q)(int, int);
    q = Add;//funcion name will return us pointer
    d = q(4, 5);
    printf("%d\n",d);

    void (*ptr)(char*);
    ptr = PrintHello;
    ptr("tom");
} 

#endif
