/*
 *  Created on: 2019年3月13日
 * 	Author: BTI-PC
 *
 * 	指针可以指向变量，也可以指向函数
 *	定义函数指针： void(*fun)(arg1,arg2)
 */

#include<stdio.h>
#include<stdlib.h>

void printHello()
{
	printf("printHello executed <<<<------\n");
}

int sum(int x, int y)
{
	return x + y;
}


int main()
{
	printf("printHello:%#x\n", (unsigned int)(long)printHello);
	printf("&printHello:%#x\n", (unsigned int)(long)&printHello);//这两个值相等....

	void (*fun)(); //定义函数指针
	fun = printHello; //给指针赋值，指向printHello()函数
	fun();
	printf("fun:%#x\n", (unsigned int)(long)fun);//存储的是printHello函数的地址
	printf("&fun:%#x\n", (unsigned int)(long)&fun);//

	int (*p_sum)(int x, int y);//定义函数指针 
	p_sum = sum;
	int sum_result = p_sum(3, 4);
	printf("sum_result=%d\n", sum_result);

	int (*p_sum2)() = sum; //函数指针可以不带形参
	int sum_result2 = p_sum2(7, 8);
	printf("sum_result2=%d\n", sum_result2);

	
	return 0;
}

