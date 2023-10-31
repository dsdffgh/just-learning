/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description: 父进程输出自身与子进程的进程ID，而子进程只输出自身的进程ID。 
 *
 *        Version:  1.0
 *        Created:  10/23/23 16:34:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
static void child()
{
printf("I'm child! my pid is %d.\n", getpid());
exit(EXIT_SUCCESS);
}
static void parent(pid_t pid_c)
{
printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
exit(EXIT_SUCCESS);
}
int main(void)
{
pid_t ret;
ret = fork();
if(ret == -1)
err(EXIT_FAILURE, "fork() failed");
if(ret == 0) {
//fork()会返回0给子进程，因此这里调用child()
child();
} else {
//fork()会返回新创建的子进程的进程ID（大于1）给父进程，因此这里调用parent()
parent(ret);
}
// 在正常运行时，不可能运行到这里
err(EXIT_FAILURE, "shouldn't reach here");
}
