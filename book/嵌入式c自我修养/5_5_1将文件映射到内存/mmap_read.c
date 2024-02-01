/*
 * =====================================================================================
 *
 *       Filename:  mmap_read.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/04/24 20:49:10
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

#define EXIT_SUCCESS 0            /*  */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    int fd;
    char *p_map;
    fd = open (argv[1], O_CREAT | O_RDWR , 0666);
    p_map = (char *) mmap (NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    if ( p_map == MAP_FAILED ) {
        perror ("mmap");
        return -1;
    }
    close (fd);
    if ( fd == -1 ) {
        perror ("close");
        return -1;
    }
    printf ("%s", p_map);
    if ( munmap (p_map, 20) == -1 ) {
        perror ("munmap");
        return -1;
    }
    return 0;
}
