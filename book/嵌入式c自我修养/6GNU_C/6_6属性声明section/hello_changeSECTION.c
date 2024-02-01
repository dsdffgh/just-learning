/*
 * =====================================================================================
 *
 *       Filename:  hello_changeSECTION.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/24 17:08:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#define EXIT_SUCCESS 0

int global_val = 8;
int uninit_val __attribute__((section(".data")));// 这个变量被放在了数据段.data


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_star
 *  Description:  
 * =====================================================================================
 */
void print_star ( )
{
    printf("*******\n");
}		/* -----  end of function print_star  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    print_star();
    return EXIT_SUCCESS;
}
