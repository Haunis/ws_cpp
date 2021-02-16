/**
 *1.void型指针：
 *		void型指针是特殊类型的指针，可以指向任意类型的数据，整数，浮点，字符串均可
 *		void型指针指向的值不可以直接被引用，因为它的长度是不固定的，必须转换成具体的类型,如char,in...
 *		应用场景：用来给函数传递通用参数
 *
 *
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;



int main()
{
	int a = 10;
	int *p =&a;
	// char **pp = &p;//error; 一级指针指向的数据类型是什么,就是什么
	int **pp = &p;

	printf("*p=%#x\n",*pp);

	return 0;
}
