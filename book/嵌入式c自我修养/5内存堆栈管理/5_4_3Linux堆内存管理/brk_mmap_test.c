/*
 * =====================================================================================
 *
 *       Filename:  brk_mmap_test.c
 *
 *    Description:  Use malloc to apply for memory blocks of different sizes
 *                  and observe their address changes in the process space.
 *
 *        Version:  1.0
 *        Created:  12/10/23 19:16:33
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

int global_val;

int
main ()
{
  int *p = NULL;
  printf ("&global_val = %p\n", &global_val);
  p = (int *) malloc (100);	// 对于用户申请的小块内存,Linux内存管理系统会在BSS段的后面批准一块内存给用户使用
  printf ("&mem_100=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 256);	// 申请内存大于128KB时,则通过mmap系统调用映射一块内存供用户使用.映射区域在堆栈段附近
  printf ("&mem_256K=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 150);
  printf ("&mem_150K=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 229);
  printf ("&mem_229K=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 128);
  printf ("&mem_128K=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 127);
  printf ("&mem_127K=%p\n", p);
  free (p);
  p = (int *) malloc (1024 * 100);
  printf ("&mem_100K=%p\n", p);
  free (p);

  while (1);
  return 0;
}
