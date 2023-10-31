#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#if 0
//介就叫函数回调
void A()
{
    printf("Hello\n");
}
void B(void(*ptr()))
{
    ptr();//回调传入的函数  call-back function that "ptr" points to
}
int main()
{
    void (*P)() = A;
    B(P);

    //这两行直接用 B(A) 表示
    B(A);
}

#endif

#if 1

//一个简单的用例：
int high_cpmpare(int a, int b)
{
    return a - b;
}

int abosolute_compare(int a, int b)
{
    return abs(a) - abs(b);
}
int BubbleSort(int A[], int n, int (*compare)(int, int))
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (compare(A[j], A[j + 1]) > 0)
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int compare_2(const void* a, const void* b)
{
    int A = *((int*)a);
    int B = *((int*)b);
    return A - B;
}
int main()
{
    int i = 0, A[] = { 3, -2, 6, 8, -51, 34, 1 };
    BubbleSort(A, 7, high_cpmpare);//函数名返回指针
    while (i < 7)
    {
        printf("%d\t", A[i++]);
    }
    printf("\n");
    BubbleSort(A, 7, abosolute_compare);
     i = 0;
    while (i < 7)
    {
        printf("%d\t", A[i++]);
    }
    printf("\n");


    int B[] = { -54,67,-1,0,64,3 };
    qsort(B, 6, sizeof(int), compare_2);
    i = 0;
    while (i < 6)
    {
        printf("%d\t", B[i++]);
    }
    printf("\n");
}

#endif
