#include <stdio.h>
int add(int, int);
__attribute__((weak)) int i = 10;//显式转化为弱符号
int main()
{
    printf("i = %d\n", i);
    int sum;
    sum = add(1, 3);
    printf("sum  = %d\n", sum);
    return 0;
}
