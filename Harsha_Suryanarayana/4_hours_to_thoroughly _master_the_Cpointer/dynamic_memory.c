#include <stdio.h>
#include <stdlib.h>

#if 0
int main()
{
	int variable; //goes on stack
    int *p;
    p = (int*)malloc(sizeof(int));//malloc����void���͵�ָ�룬ָ����������ڴ�ĵ�һ���ֽڵĵ�ַ
    *p = 70;
    printf("%d\t%d",p,*p);
    free(p);

    p = (int*)malloc(2*sizeof(int));//������벻���ڴ�᷵��NULL
    p[0] = 20;
    p[1] = 254;
    printf("%d\t%d\n",p,p[1]);

    /*
    ��c++�������ڴ���������������
    p = new int;
    *p = 54;
    delete p;

    p = new int[20];
    delete p;
    ��������c��һ��ǿ��ת������
    */
}
#endif

#if 1
int main()
{
    /*
    void *p = malloc(7*sizeof(int));
    *p = 1;  error:voidָ�벻��ֱ�ӽ�����
    */

    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    // int A[n]; error: �±겻���Ǳ���
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
    //��ʹfree�ˣ�Ҳ���ǿ��Է�������ڴ��ֵ
    A[4] = 24;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");

    int *B = (int *)calloc(n, sizeof(int)); //�������ʼ��
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
    
    int *C = (int *)realloc(B, 2 * n * sizeof(int)); //�������չ����չ�����������µ��ڴ�
                                                       //��֮ǰ�Ŀ�����ȥȻ��ɾ��
    for (i = 0; i < 2*n; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
    //int *C = (int *)realloc(B, 0);�൱��free(A)
    //int *C = (int *)realloc(NULL, n * sizeof(int));�൱��malloc
    //int *B = (int *)realloc(B, 2 * n * sizeof(int));�����ʱ����÷�
}
#endif
