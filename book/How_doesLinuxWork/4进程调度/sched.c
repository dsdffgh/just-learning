/*
 * =====================================================================================
 *
 *       Filename:  sched.c
 *
 *    Description:  在同时运行一个或多个一味消耗CPU时间执行处理的进程时，采集以下统计信息。
 *                    ●在某一时间点运行在逻辑CPU上的进程是哪一个
 *                    ●每个进程的运行进度通过分析这些信息，来确认本章开头对调度器的描述是否正确。
 *                 实验程序的设计如下。
 *                   ●命令行参数
 *                    o第1个参数（n）：同时运行的进程数量
 *                    o第2个参数（total）：程序运行的总时长（单位：毫秒）
 *                    o第3个参数（resol）：采集统计信息的间隔（单位：毫秒）
 *                   ●令 n个进程同时运行，然后在全部进程都结束后结束程序的运行。各个进程按照以下要求运行
 *                    o在消耗total毫秒的CPU时间后结束运行
 *                    o每resol毫秒记录一次以下3个数值：①每个进程的唯一ID（0~ n - 1的各个进程独有的编号）；②从程序开始运行到记录的时间点为止经过的时间（单位：毫秒）；③进程的进度（单位：%）o在结束运行后，把所有统计信息用制表符分隔并逐行输出
 *
 *        Version:  1.0
 *        Created:  10/23/23 18:15:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define NLOOP_FOR_ESTIMATION 1000000000UL
#define NSECS_PER_MSEC 1000000UL
#define NSECS_PER_SEC 1000000000UL

static unsigned long nloop_per_resol;
static struct timespec start;

static inline long diff_nsec(struct timespec before, struct timespec after)
{
    return ((after.tv_sec * NSECS_PER_SEC + after.tv_nsec) - (before.tv_sec * NSECS_PER_SEC + before.tv_nsec));
}

static unsigned long estimate_loops_per_msec()
{
    struct timespec before, after;
    clock_gettime(CLOCK_MONOTONIC, &before);

    unsigned long i;
    for (i = 0; i < NLOOP_FOR_ESTIMATION; i++)
        ;

    clock_gettime(CLOCK_MONOTONIC, &after);

    int ret;
    return NLOOP_FOR_ESTIMATION * NSECS_PER_MSEC / diff_nsec(before, after);
}

static inline void load(void)
{
    unsigned long i;
    for (i = 0; i < nloop_per_resol; i++)
        ;
}

static void child_fn(int id, struct timespec *buf, int nrecord)
{
    int i;
    for (i = 0; i < nrecord; i++)
    {
        struct timespec ts;

        load();
        clock_gettime(CLOCK_MONOTONIC, &ts);
        buf[i] = ts;
    }
    for (i = 0; i < nrecord; i++)
    {
        printf("%d\t%ld\t%d\n", id, diff_nsec(start, buf[i]) / NSECS_PER_MSEC, (i + 1) * 100 / nrecord);
    }
    exit(EXIT_SUCCESS);
}

static pid_t *pids;

int main(int argc, char *argv[])
{
    int ret = EXIT_FAILURE;

    if (argc < 4)
    {
        fprintf(stderr, "usage: %s <nproc> <total[ms]> <resolution[ms]>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int nproc = atoi(argv[1]);
    int total = atoi(argv[2]);
    int resol = atoi(argv[3]);

    if (nproc < 1)
    {
        fprintf(stderr, "<nproc>(%d) should be >= 1\n", nproc);
        exit(EXIT_FAILURE);
    }

    if (total < 1)
    {
        fprintf(stderr, "<total>(%d) should be >= 1\n", total);
        exit(EXIT_FAILURE);
    }

    if (resol < 1)
    {
        fprintf(stderr, "<resol>(%d) should be >= 1\n", resol);
        exit(EXIT_FAILURE);
    }

    if (total % resol)
    {
        fprintf(stderr, "<total>(%d) should be multiple of <resolution>(%d)\n", total, resol);
        exit(EXIT_FAILURE);
    }
    int nrecord = total / resol;

    struct timespec *logbuf = (struct timespec*)malloc(nrecord * sizeof(struct timespec));
    if (!logbuf)
        err(EXIT_FAILURE, "failed to allocate log buffer");

    puts("estimating the workload which takes just one milli-second...");
    nloop_per_resol = estimate_loops_per_msec() * resol;
    puts("end estimation");
    fflush(stdout);

    pids = (pid_t*)malloc(nproc * sizeof(pid_t));
    if (pids == NULL)
        err(EXIT_FAILURE, "failed to allocate pid table");

    clock_gettime(CLOCK_MONOTONIC, &start);

    ret = EXIT_SUCCESS;
    int i, ncreated;
    for (i = 0, ncreated = 0; i < nproc; i++, ncreated++)
    {
        pids[i] = fork();
        if (pids[i] < 0)
        {
            int j;
            for (j = 0; j < ncreated; j++)
                kill(pids[j], SIGKILL);
            ret = EXIT_FAILURE;
            break;
        }
        else if (pids[i] == 0)
        {
            // children
            child_fn(i, logbuf, nrecord);
            /* shouldn't reach here */
            abort();
        }
    }
    // parent
    for (i = 0; i < ncreated; i++)
        if (wait(NULL) < 0)
            warn("wait() failed.");

    exit(ret);
}