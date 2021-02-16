/*
 *  Created on: 2019年3月13日
 * 	Author: BTI-PC
 *
 * 	指针可以指向变量，也可以指向函数
 *
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{

	printf("\n-----------------1.指针长度-----------------------------\n");

	//所有指针类型的长度都是一样的,之所以分辨指针类型时为了方便位移运算
	//32位系统是4，64位系统是8。如果使用了32位编译器结果就是4
	printf("sizeof(short*) :  %lu\n", sizeof(short*));
	printf("sizeof(int*) :  %lu\n", sizeof(int*));
	printf("sizeof(long*) :  %lu\n", sizeof(long*));
	printf("sizeof(float*) :  %lu\n", sizeof(float*));
	printf("sizeof(double*) :  %lu\n", sizeof(double*));
	printf("sizeof(char*) :  %lu\n", sizeof(char*));

	printf("\n-----------------2.变量指针-----------------------------\n");
	int i = 4;
	int *i_p = &i; //定义一个int型的指针变量，指针变量的值必须是int型变量的地址
	int **i_pp = &i_p; //定义一个二级指针，它的值必须是一级指针变量的地址

	printf("i address &i :%#x\n", (unsigned int)(long)&i);
	printf("i address i_p :%#x\n", (unsigned int)(long)i_p);//这两个值相等，都是i的地址

	printf("i 的值是 *i_p:  %d\n", *i_p); //*i_p--指针所指向的地址存放的数据
	printf("i 的值是  **i_pp:  %d\n", **i_pp);
	printf("i_p的值，也就是i的地址是 *i_pp :  %#x\n", (unsigned int)(long)*i_pp);

	printf(" &i_p=%#x, i_pp=%#x", (unsigned int)(long)&i_p, (unsigned int)(long)i_pp);

	return 0;
}

