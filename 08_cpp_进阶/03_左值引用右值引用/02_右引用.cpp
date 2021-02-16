/**
 *	std::move():
 * 		https://zhuanlan.zhihu.com/p/55229582
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

void fun(int &&num) //右值引用作为函数参数
{
	printf("fun right --> &num=%#x\n", &num);
	num = num * 2;
}

int main()
{
	printf("\n--------------------1.对立即数取引用----------------------\n");
	int &&r_i = 1; //r_i类型是右值引用，是对右值1的引用；但其本身是左值，具名变量都是左值
	printf("r_i = %d,&r_i = %#x\n", r_i, &r_i);

	printf("\n--------------------2.对左值使用move()----------------------\n");
	int i2 = 10; //i2是左值
	printf("i2=%d, &i2 = %#x\n", i2, &i2);
	// int &&r_i2 = i;	//error,右值引用只能对右值取引用
	int &&r_i2 = std::move(i2); //通过std::move()获取左值的右值引用;r_i2是右值引用类型,但是是左值
	printf("r_i2 = %d,&r_i2 = %#x\n", r_i2, &r_i2);

	r_i2 = i2 * 2;
	printf("i2 = %d\n", i2); //i2的值也会改变,因为通过std::move(),i2和r_i2指向同一块内存

	printf("\n--------------------3.调用参数为右引用的函数----------------------\n");
	// fun(r_i2);//error;只能传右值

	printf("before  r_i2 = %d\n", r_i2);
	fun(std::move(i2)); //可以理解将i的引用传过去
	printf("after  r_i2 = %d\n", r_i2);
	printf("i = %d\n", i2); //i会改变

	return 0;
}
