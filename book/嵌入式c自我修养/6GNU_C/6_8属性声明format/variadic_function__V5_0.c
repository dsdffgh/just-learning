/*
 * =====================================================================================
 *
 *       Filename:  variadic_function__V5_0.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/24 22:15:13
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
#include <stdarg.h>

#define EXIT_SUCCESS 0

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  my_printf
 *  Description:  
 * =====================================================================================
 */
void __attribute__((format(printf,1,2)))
my_printf ( char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}		/* -----  end of function my_printf  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    int num = 0;
    my_printf("I'm robot, I have %d car\n", num);
    return EXIT_SUCCESS;
}
