
/**
 * 函数在使用前必须先定义:
 * 		可以在main函数前面先声明，在main函数后面再具体实现
 * 		也可以在main函数之前直接实现
 * 
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int add(int i, int j) //直接实现函数
{
	return i + j;
}

int sub(int i, int j); //声明函数，在main函数后面实现函数的具体功能

long doFactorial(int i) //递归函数,阶乘
{
	if (i > 1)
	{
		return i * doFactorial(i - 1);
	}
	return 1;
}

int main()
{

	printf("-----------------1.函数基础-------------------\n");
	int a = 10, b = 20;
	int ret = add(a, b);
	printf("add ret = %d\n", ret);
	ret = sub(a, b);
	printf("sub ret = %d\n", ret);

	printf("-----------------2.递归调用-------------------\n");
	long f = doFactorial(4);
	cout << "f = " << f << endl;

	return 0;
}
int sub(int i, int j)
{
	return i - j;
}
