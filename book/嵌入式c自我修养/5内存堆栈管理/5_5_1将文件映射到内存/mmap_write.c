/*
 * =====================================================================================
 *
 *       Filename:  mmap_write.c
 *
 *    Description:  不通过文件I/O对文件进行读写,通过mmap映射的内存进行读写
 *                  addr 进程中要映射的虚拟内存起始地址,一般为NULL
 *                  legth 要映射的虚拟内存大小
 *                  prot 内存保护标志 PROT_READ,PROT_WRITE,PROT_EXEC
 *                  flags 映射对象类型 有MAP_SHARED,MAP_FIXED,MAP_PRIVATE
 *                  fd 要映射的文件描述符
 *                  offset 文件位置偏移
 *                  mmap 以页为单位进行操作: 参数addr和offset必需按页对齐
 *
 *        Version:  1.0
 *        Created:  01/03/24 20:50:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define EXIT_SUCCESS 0		/*  */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main (int argc, char *argv[])
{
  int fd;
  char *p_map;
  fd = open (argv[1], O_CREAT | O_RDWR | O_TRUNC, 0666);
  write (fd, "", 1);		// 系统调用
  p_map = (char *) mmap (NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (p_map == MAP_FAILED)
    {
      perror ("mmap");
      return -1;
    }

  if (fd == -1)
    {
      perror ("close");
      return -1;
    }
  memcpy (p_map, "hello world!\n", 14);
  sleep (5);
  close (fd);
  if (munmap (p_map, 20) == -1)
    {
      perror ("munmap");
      return -1;
    }
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
