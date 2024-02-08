/*
 * =====================================================================================
 *
 *       Filename:  ptmalloc_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/10/23 21:01:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include    <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    char* p_32k, *p_64k, *p_120k;
    char *p_12k, *p_80k, *p_132k;

    p_32k = malloc(32*1024);
    p_64k = malloc(64*1024);
    p_120k = malloc(120*1024);
    p_132k = malloc(132*1024);
    printf("p_32k: %p\n", p_32k);
    printf("p_64k: %p\n", p_64k);
    printf("p_120k: %p\n", p_120k);
    printf("p_132k: %p\n", p_132k);

    free(p_32k);
    p_12k = malloc(12*1024);
    printf("p_12k: %p\n", p_12k);

    free(p_64k);
    p_80k = malloc(80*1024);
    printf("p_80k: %p\n", p_80k);

    free(p_132k);
    free(p_12k);
    free(p_80k);
    free(p_120k);
    return 0;

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
