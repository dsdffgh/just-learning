/*
 * =====================================================================================
 *
 *       Filename:  inline.c
 *
 *    Description:  用static inline修饰，编译器不一定会做内联展开。
 *                  要明确告诉一定展开或不展开，用noline/always_inline
 *
 *        Version:  1.0
 *        Created:  02/08/24 10:45:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

static inline
__attribute__((always_inline)) int func(int a)
{
    return a + 1;
}

static inline void print_num(int a)
{
    printf("%d\n",a);
}

int main()
{
    int i;
    i = func(3);
    print_num(10);
    return 0;
}
