/*
 * =====================================================================================
 *
 *       Filename:  mprotect.c
 *
 *    Description:  使用memalign()函数申请一块以页大小对齐的512字节的内存
 *                  ,设为只读,然后写入数据
 *
 *        Version:  1.0
 *        Created:  01/05/24 12:17:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <malloc.h>
#include <sys/mman.h>

#define EXIT_SUCCESS 0

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    int *p;
    p = memalign(4096,512);
    *p = 100;
    printf("*p = %d\n", *p);
    mprotect(p, 512, PROT_READ);
    *p = 200;
    printf("*p = %d\n", *p);

    free(p);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
