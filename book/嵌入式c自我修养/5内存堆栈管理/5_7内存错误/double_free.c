/*
 * =====================================================================================
 *
 *       Filename:  double_free.c
 *
 *    Description:  多次释放会触发段错误
 *
 *        Version:  1.0
 *        Created:  01/04/24 23:11:16
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
    char *p;
    p = (char *) malloc (64);
    free(p);
    free(p); // 发生段错误
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
