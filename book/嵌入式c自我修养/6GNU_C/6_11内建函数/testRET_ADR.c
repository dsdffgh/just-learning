/*
 * =====================================================================================
 *
 *       Filename:  testRET_ADR.c
 *
 *    Description:  测试内建函数，返回返回地址
 *
 *        Version:  1.0
 *        Created:  02/08/24 11:10:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void f()
{
    int *p;
    p=__builtin_return_address(0);
    printf("f    return address: %p\n",p);
    p=__builtin_return_address(1);
    printf("func return address: %p\n",p);
    p=__builtin_return_address(2);
    printf("main return address: %p\n",p);
    printf("\n");
}

void func()
{
    int *p;
    p=__builtin_return_address(0);
    printf("func return address: %p\n",p);
    p=__builtin_return_address(1);
    printf("main return address: %p\n",p);
    p=__builtin_frame_address(0);
    printf("func frame: %p\n",p);
    p=__builtin_frame_address(1);
    printf("main frame: %p\n",p);
    printf("\n");
    f();
}

int main()
{
    
    int *p;
    p=__builtin_return_address(0);
    printf("main return address: %p\n",p);
    p=__builtin_frame_address(0);
    printf("main frame: %p\n",p);
    printf("\n");
    func();
    printf("bye!!\n");
    return 0;
}
