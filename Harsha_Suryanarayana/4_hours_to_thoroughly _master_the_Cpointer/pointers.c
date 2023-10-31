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
	printf("Address = %d\n", p0);//p0+1,*p0都是错的
	printf("Address = %d\n", *p1);
	//printf("Address = %d\n", *p0);//空指针不能解引用
	printf("\n\n");
#endif

	/***************************************/

#if 0
	//指向指针的指针:
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
void print(const char c[])	//c会将它认为是 char *c
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
	char* c = "hello";//		string gets stored as compile time costant  字符串放在常量区
	//在vs2022   这里错了:错误(活动)	E0144	"const char *" 类型的值不能用于初始化 "char *" 类型的实体
	//const char* c = "hello";
	//https://www.geeksforgeeks.org/storage-for-strings-in-c/
	print(c);
}
#endif

#if 0
//二维数组
int main()
{
	int  B[2][3] = { 2,4,64,354,34,354 };
	//int* p = B;// error    t-D返回的是指向一维数组的指针
	//int* p[3] = B;// error    //对于int *p[3]：这里的“p”是 一个大小为 3 的数组，可以存储整数指针
	int (*p)[3] = B;// 数组名返回了一个一维数组；这是个指向一维数组的指针   //对于int (*p)[3]：这里的“p”是指针的变量名，可以指向一个三整数数组
//https://www.geeksforgeeks.org/difference-between-int-p3-and-int-p3/ 详情参考

	printf("%d\t%d\n", B, &B[0]);

	printf("%d\t%d\n", *B, B[0]);//这两者都是一维数组的名字，和 &B[0][0]相当

	printf("%d\t%d\n", **B, *B[0]);
	//一级指针指向元素地址
	//二维数组是一维数组的数组，即指针的指针，故进行一次解引用，得到的还是地址。懂了吗，zqz！
	//数组名返回指向元素的指针

	printf("%d\t%d\n", B+1, &B[1]);

	printf("%d\t%d\n", *(B+1), B[1]);

	/*  B[i][j] = *(B[i] + j)
				= *(*(B + i) + j)
				*/
}
#endif

#if 1
//void fun(int (*A)[2][2])
//假如说传一个多维数组，后几维应该强制指定
int main()
{
	int C[3][2][2] = { { {2,5} , {7,9} },
					   { {3,4} , {6,1} },
					   { {0,8} , {11,13} } };
	printf("%d	%d	%d	%d	%d\n", C, *C, C[0], &C[0][0], &C[0][0][0]);//in fact, they are 'int(*)[2][2]','int(*)[2]','int(*)[2]','int(*)[2]','int*'
	printf("%d\n", *(C[0][0] + 1));

	//fun(C) 就像这样
}
#endif