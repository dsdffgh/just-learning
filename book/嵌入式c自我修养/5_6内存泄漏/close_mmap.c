/*
 * =====================================================================================
 *
 *       Filename:  close_mmap.c
 *
 *    Description:  关闭mmap映射功能,了解mallopt()对内存分配器的调整
 *
 *        Version:  1.0
 *        Created:  01/01/24 15:10:00
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
#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  当申请大于M_MMAP_THRESHOLD的内存时,
 *                内存分配器并没有到mmap区域映射内存,而是直接从堆区分配
 * =====================================================================================
 */
int
main (int argc, char *argv[])
{
    char *p1,*p2,*p3;
    mallopt(M_MMAP_MAX,0);
    p1 = (char *)malloc(32*1024);
    p2 = (char *)malloc(120*1024);
    p3 = (char *)malloc(132*1024);
    printf("p1: %p\n",p1);
    printf("p2: %p\n",p2);
    printf("p3: %p\n",p3);
    free(p1);
    free(p2);
    free(p3);
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
