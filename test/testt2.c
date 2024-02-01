/*
 * =====================================================================================
 *
 *       Filename:  testt2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/23 16:38:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include<stdio.h>
int main() {
    int a[3][3], i, j, b[3][3];
    //通过指针数组来访问二维数组
    int (*p1)[3], (*p2)[3];
    p1 = a, p2 = b;
    while (1) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (scanf("%d", &a[i][j]) == EOF)return 0;
            }
        }
        //将行转换成列存入数组b中
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                *(*(p2 + j) + i) = *(*(p1 + i) + j);
            }
        }
        //输出数组b
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%-2d", (*(*(p2 + i) + j)));
                if (j == 2) { printf("\n"); }
            }
        }
    }
}

