/*
 * =====================================================================================
 *
 *       Filename:  mem_leak.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/24 12:29:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>

#define EXIT_SUCCESS 0

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    char *p, *q;
    p = (char *)malloc(32);
    q = (char *)malloc(32);
    free(p);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
