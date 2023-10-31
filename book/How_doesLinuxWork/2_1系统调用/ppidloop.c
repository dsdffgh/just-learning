/*
 * =====================================================================================
 *
 *       Filename:  ppidloop.c
 *
 *    Description: 循环执行getppid(),获取父进程的进程ID
 *
 *        Version:  1.0
 *        Created:  10/23/23 15:02:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <unistd.h>

int main()
{
    while(1)
        getppid();
}
