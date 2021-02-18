#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy

int main()
{

	printf("\n----------------各个数据类型长度-------------------\n");
	printf("char %lu\n", sizeof(char)); //1
	printf("short %lu\n", sizeof(short));	//2
	printf("int %lu\n", sizeof(int));		//4
	printf("long %lu\n", sizeof(long));		//4--linux gcc 8
	printf("float %lu\n", sizeof(float));	//4
	printf("double %lu\n", sizeof(double)); //8

	printf("long long %lu\n", sizeof(long long)); //8无符号位打印
	int a = 8;
	int *p = &a;
	printf("sizeof(p):%lu", sizeof(p)); //8

	return 0;
}
