/*
 *****************************************************
 *
 *
 *
 *
 *	Desprition: 常量被编译器保存在.rodata的只读数据段中 
 *	objdump -h .\bin\ConstanatStore.out
 *	x86_64环境下是.rdata
 *	unix下是.rodata
 *
 *****************************************************
 */
#include <stdio.h>

#define HELLO "world\n"
char *p = "hello ubuntu!\n";

int main()
{
	char c_val = 'A';
	printf("hello %s",HELLO);
	printf("%s",p);
	printf("c_val = %c\n",c_val);
	return 0;
}
