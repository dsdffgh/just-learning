#include <stdio.h>  
#if 0
int main()
{
#if 0
	int m = 1025;
	int* p1 = &m;
	void* p0;
	p0 = p1;
	printf("Address = %d\n", p1);
	printf("Address = %d\n", p0);//p0+1,*p0���Ǵ��
	printf("Address = %d\n", *p1);
	//printf("Address = %d\n", *p0);//��ָ�벻�ܽ�����
	printf("\n\n");
#endif

	/***************************************/

#if 0
	//ָ��ָ���ָ��:
	int x = 5;
	int* p = &x;
	int** q = &p;
	int*** r = &q;

	printf("*p = %d\n", *p);
	printf("p = %d\n", p);
	printf("*q = %d\n", *q);
	printf("**q= %d\n", **q);
	printf("q= %d\n", q);
	printf("*r= %d\n", *r);
	printf("**r= %d\n", **r);
	printf("***r= %d\n", ***r);
#endif

	/***************************************/

#if 1 
	int a[4] = { 2,5,6,4 };

	printf("%d\t%d\n", a,a+3);//(a+i) = &a[i]
	printf("%d\t%d\n", *a,*(a+3));

	int* p = a;
	
	printf("a= %d\n", a);
	printf("p= %d\n", p);
	printf("*p= %d\n", *p);
	p++;
	//a++;//invaild		//lvalue required as increment operand
	printf("*a= %d\n", *a);
	printf("p= %d\n", p);
	printf("*p= %d\n", *p);
#endif

	/*************************************/
}  
#endif

#if 0
//character arrays and pointer
void print(const char c[])	//c�Ὣ����Ϊ�� char *c
{
	while (*c != '\0')
	{
		printf("%c\n", *c);
		printf("%d\n", c);
		c++;
	}
}
int main()
{
	char C[4] ;
	C[0] = 'J';C[1] = 'H';C[2] = 'O';C[3] = 'N';
	printf("%s\n",C);

	//char c[20] = "hello";//		string gets sotred in the space for array
	char* c = "hello";//		string gets stored as compile time costant  �ַ������ڳ�����
	//��vs2022   �������:����(�)	E0144	"const char *" ���͵�ֵ�������ڳ�ʼ�� "char *" ���͵�ʵ��
	//const char* c = "hello";
	//https://www.geeksforgeeks.org/storage-for-strings-in-c/
	print(c);
}
#endif

#if 0
//��ά����
int main()
{
	int  B[2][3] = { 2,4,64,354,34,354 };
	//int* p = B;// error    t-D���ص���ָ��һά�����ָ��
	//int* p[3] = B;// error    //����int *p[3]������ġ�p���� һ����СΪ 3 �����飬���Դ洢����ָ��
	int (*p)[3] = B;// ������������һ��һά���飻���Ǹ�ָ��һά�����ָ��   //����int (*p)[3]������ġ�p����ָ��ı�����������ָ��һ������������
//https://www.geeksforgeeks.org/difference-between-int-p3-and-int-p3/ ����ο�

	printf("%d\t%d\n", B, &B[0]);

	printf("%d\t%d\n", *B, B[0]);//�����߶���һά��������֣��� &B[0][0]�൱

	printf("%d\t%d\n", **B, *B[0]);
	//һ��ָ��ָ��Ԫ�ص�ַ
	//��ά������һά��������飬��ָ���ָ�룬�ʽ���һ�ν����ã��õ��Ļ��ǵ�ַ��������zqz��
	//����������ָ��Ԫ�ص�ָ��

	printf("%d\t%d\n", B+1, &B[1]);

	printf("%d\t%d\n", *(B+1), B[1]);

	/*  B[i][j] = *(B[i] + j)
				= *(*(B + i) + j)
				*/
}
#endif

#if 1
//void fun(int (*A)[2][2])
//����˵��һ����ά���飬��άӦ��ǿ��ָ��
int main()
{
	int C[3][2][2] = { { {2,5} , {7,9} },
					   { {3,4} , {6,1} },
					   { {0,8} , {11,13} } };
	printf("%d	%d	%d	%d	%d\n", C, *C, C[0], &C[0][0], &C[0][0][0]);//in fact, they are 'int(*)[2][2]','int(*)[2]','int(*)[2]','int(*)[2]','int*'
	printf("%d\n", *(C[0][0] + 1));

	//fun(C) ��������
}
#endif