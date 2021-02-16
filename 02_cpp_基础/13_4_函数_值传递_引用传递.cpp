
/**
 * 引用传递：函数原型使用如int &a接收
 *
 */

#include <iostream>
#include <stdio.h>
using namespace std;

void add(int i) //_Z3addi:
{
	printf("&i=%#x\n", &i);
	i = i * 2;
}

//引用传递,只在C++适用。C语言里适用指针做相同的操作；
//i和传入的变量是同一个变量,地址相等
void doDouble(int &i) //_Z8doDoubleRi:
{
	printf("&i=%#x\n", &i);
	i = i * 2;
}

int main()
{
	printf("-----------------1.值传递-----------------\n");
	int a = 1;
	printf("&a=%#x\n", &a);

	printf("after : a=%d\n", a);

	add(a);

	printf("after : a=%d\n", a);

	printf("\n-----------------2.引用传递-----------------\n");
	int b = 1;

	printf("&b=%#x\n", &b);
	doDouble(b);
	printf("after : b=%d\n", b);

	//	system("pause");
	return 0;
}
