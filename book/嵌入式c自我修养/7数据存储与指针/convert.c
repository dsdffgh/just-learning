/*
 * =====================================================================================
 *
 *       Filename:  convert.c
 *
 *    Description:  看看是否会死循环
 *
 *        Version:  1.0
 *        Created:  02/08/24 18:17:07
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_star
 *  Description:  
 * =====================================================================================
 */
int print_star ( signed int len )
{
    int i=1;
    if(len<0)
    {
        printf("Error!\n");
        return -1;
    }

    while(len-- > 0)
    {
        if(i++%20==0)   printf("\n");
        printf("*");
    }
    printf("\n");
    return 0;
}		/* -----  end of function print_star  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    print_star(-1);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
