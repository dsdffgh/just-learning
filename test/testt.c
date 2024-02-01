/*
 * =====================================================================================
 *
 *       Filename:  testt.c
 *
 *    Description:  每年五一学校们就纷纷开始放假，wzj说:“如果五一放5天的假，那么如果五一当天是星期一，加上两个周末末，不就有9天的假期了!如果是五一当天是星期二，加上后面连着的周末，就有6天的假期!这样的话每年的五一放假的天数都有可能不同，让我来算算各个年的五一连续放几天假!”，当然并不存在放假却不补课的学校，但是wzj开心地算了起来。

Input
输入有多组数据，第一行输入一个T表示有T组数据，每组数据里，含一个数字year(1928 <= year <= 9999))，表示年份。

Output
对于每组数据，输出那一年的五一加上连在一起的周末的放假天数。
 *
 *        Version:  1.0
 *        Created:  12/09/23 22:37:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#pragma warning (disable:4996)
// 函数声明
void  transposeMatrix (int  matrix[3][3]);
int  
main ()
{
      			// 读取测试组数
            for  (; 1;)
        
    {
              int  matrix[3][3];
              		// 读取矩阵元素
	        for  (int  i = 0; i < 3; ++i)
	        
	{
	              for  (int  j = 0; j < 3; ++j)
	                
	    {
	                      if
		 (scanf ("%d", &matrix[i][j]) == EOF)
		return  0;
	                }
	        }
              		// 调用函数进行矩阵转置
	        transposeMatrix (matrix);
              		// 输出转置后的矩阵
	        for  (int  i = 0; i < 3; ++i)
	        
	{
	              for  (int  j = 0; j < 3; ++j)
	                
	    {
	                      printf ("%d", matrix[i][j]);
	                      	// 输出空格或换行
		                if  (j < 2)
		{
		                      printf (" ");
		                }
	                      
	      else
		 
		{
		                      printf ("\n");
		                }
	                }
	        }
              		// 输出空行，分隔测试数据
	                 printf ("\n");
                 }
           return  0;
}

// 函数定义：矩阵转置
void  
transposeMatrix (int  matrix[3][3])
{
      int  temp;
      for  (int  i = 0; i < 3; ++i)
    {
              for  (int  j = i + 1; j < 3; ++j)
	{
	              	// 交换元素
	                temp = matrix[i][j];
	              matrix[i][j] = matrix[j][i];
	              matrix[j][i] = temp;
	        }
        }
}
