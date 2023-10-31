/* ************************************************************************
> File Name:     param.c
# Author:       Theonesssssssss
# mail:      whyunotdo@qq.com
> Created Time:  Mon Oct 16 15:32:55 2023
> Description:   
 ************************************************************************/

#include<stdio.h>

int f(int ag1 ,int ag2 ,int ag3 ,int ag4 ,int ag5 ,int ag6)
{
    int s = 0;
    s = ag1 + ag2 + ag3 + ag4 +ag5 + ag6;
    return s;
}
int main()
{
    int sum = 0;
    f(1,2,3,4,5,6);
    printf("sum:%d\n", sum);
    return 0;
}
