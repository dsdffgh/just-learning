/*
 * =====================================================================================
 *
 *       Filename:  MTtrace_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/10/23 23:06:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <mcheck.h>

#define EXIT_SUCCESS 0            /*  */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
mtrace();// 开启跟踪
    char *p, *q;
    p = (char *)malloc(8);
    q = (char *)malloc(8);
    strcpy(p, "hello");
    strcpy(q, "world");
    free(p);
muntrace();// 关闭跟踪
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
