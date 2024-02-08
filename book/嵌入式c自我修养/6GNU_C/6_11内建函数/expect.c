/*
 * =====================================================================================
 *
 *       Filename:  expect.c
 *
 *    Description:  分支预测优化 likely unlikely
 *
 *        Version:  1.0
 *        Created:  02/08/24 13:15:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#include <stdlib.h>

#define EXIT_SUCCESS 0
#define unlikely(x) __builtin_expect(!!(x),0)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    int a;
    scanf("%d",&a);
    if( unlikely(a==0) )
    {
        printf("%d",1);
        printf("%d\n",2);
    }
    else
    {
        printf("%d",5);
        printf("%d\n",6);

    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
