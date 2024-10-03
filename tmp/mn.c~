
//C语言输出矩阵马鞍点

#include<stdio.h>  

void Input_Matrix(int m,int n,int a[100][100])              //输入矩阵元素
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void Output_Matrix(int m, int n, int a[100][100])    //输出矩阵元素
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }
}

void Matrix_Mn(int m, int n, int a[100][100])     //输出矩阵马鞍点
{
    int flag = 0;
    int min, max, k, l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            min = a[i][j];
            for (k = 0; k < m; k++)
            {
                if (min < a[i][k])
                    break;
            }
            if (k == m)
            {
                max = a[i][j];
                for (l = 0; l < n; l++)
                {
                    if (max > a[l][j])
                        break;
                }
                if (l == n)
                {
                    printf("%-5d%-5d\n", i, j);
                    printf("矩阵元素为：a[%d][%d]=%d\n",i,j, a[i][j]);
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("该矩阵没有马鞍点！\n");
    }
}
int main(void)
{
    int m, n;
    int a[100][100];

    for (;;)
    {

        printf("请输入矩阵的行数和列数：\n");
        scanf("%d %d", &n, &m);
        printf("请输入矩阵中的元素：\n");
        Input_Matrix(m, n, a);
        printf("矩阵输出为：\n");
        Output_Matrix(m, n, a);
        printf("马鞍点输出(该点所在的行数和列数)：\n");
        Matrix_Mn(m, n, a);
    }
    return 0;
}
