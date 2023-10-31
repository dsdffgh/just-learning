#include <stdio.h>
#include <stdlib.h>

#if 0
int main()
{
	int variable; //goes on stack
    int *p;
    p = (int*)malloc(sizeof(int));//malloc返回void类型的指针，指向所申请的内存的第一个字节的地址
    *p = 70;
    printf("%d\t%d",p,*p);
    free(p);

    p = (int*)malloc(2*sizeof(int));//如果申请不到内存会返回NULL
    p[0] = 20;
    p[1] = 254;
    printf("%d\t%d\n",p,p[1]);

    /*
    在c++中申请内存是用两个操作符
    p = new int;
    *p = 54;
    delete p;

    p = new int[20];
    delete p;
    不用像在c中一样强制转换类型
    */
}
#endif

#if 1
int main()
{
    /*
    void *p = malloc(7*sizeof(int));
    *p = 1;  error:void指针不能直接解引用
    */

    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    // int A[n]; error: 下标不能是变量
    int *A = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
    free(A);
    //即使free了，也还是可以访问这块内存的值
    A[4] = 24;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");

    int *B = (int *)calloc(n, sizeof(int)); //申请后会初始化
    for (i = 0; i < n; i++)
    {
        printf("%d\t", B[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        B[i] = i + 1;
    }
    free(B);
    
    int *C = (int *)realloc(B, 2 * n * sizeof(int)); //如果能扩展就扩展，否则申请新的内存
                                                       //把之前的拷贝过去然后删除
    for (i = 0; i < 2*n; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
    //int *C = (int *)realloc(B, 0);相当于free(A)
    //int *C = (int *)realloc(NULL, n * sizeof(int));相当于malloc
    //int *B = (int *)realloc(B, 2 * n * sizeof(int));大多数时候的用法
}
#endif
