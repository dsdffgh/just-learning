/*
 * =====================================================================================
 *
 *       Filename:  heap_overwrite.c
 *
 *    Description:  内存踩踏
 *
 *        Version:  1.0
 *        Created:  01/04/24 23:33:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
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
    p = malloc (16);
    q = malloc (16);
    strcpy(p, "hello world! hello zhaixue.cc!\n");
    printf("%s\n",p);
    printf("%s\n",q);
    while(1);
    free(q);
    free(p);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
