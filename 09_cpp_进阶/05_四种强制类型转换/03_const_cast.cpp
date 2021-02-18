/*
 *  Created on: 2019年3月11日
 *
 * 	去掉const:
 * 	https://blog.csdn.net/anlian523/article/details/95751762
 * 
 *	const_cast<type-i> (expression):
 *		expression:必须是引用或者指针,int转int都不行
 *
 *		如果expression本身不是常量，获得的权限是合法的
 *		如果expression是常量，使用const_cast再写的后果是未定义的
 *
 *		用途:
 *			用于修改类型的const或volatile属性，不能对非指针或非引用的变量添加或移除const
 *			只有当对象原本就是非常量时，才是正确的行为。
 *
 */
#include <iostream>
#include <stdio.h>
using namespace std;

void func(const int &a) //形参为a，引用指向const int
{
	int &b = const_cast<int &>(a); //去掉const限定，因为原本为非常量
	b++;
	return;
}
int main()
{

	printf("\n-----------------1.1 去掉int指针const属性-------------------------\n");
	const int g = 20;
	//int h = const_cast<int>(g); //error.不允许对普通数据进行操作
	const int *g_p = &g;//常量指针
	printf("g_p = %#x\n", g_p);
	int *h = const_cast<int *>(g_p); //去掉const常量const属性
	printf("h = %#x\n", h);			 //和g_p值一样，指向同一块内存区域
	*h = 40;						 //可以赋值
	printf("g = %d\n", g);			 //20,g还是20不变；发生了常量折叠，在编译阶段g已经被替换
	printf("*(&g) = %d\n", *(&g));	 //40

	printf("\n-----------------1.2 去掉char指针const属性-------------------------\n");
	const char *g3 = "hello";		   //常量指针;指针指向的内容不可修改
	char *h3 = const_cast<char *>(g3); //去掉const指针const属性
	// *(h3+1) = 'x';//error,虽然去掉了const属性，但是还是不可以修改
	printf("%s\n", h3);

	printf("\n-----------------2.去掉左值引用const属性-------------------------\n");

	const int g1 = 30;
	const int &g2 = g1;				 //加const修饰可以为左引用赋值右值
	int &h1 = const_cast<int &>(g1); //去掉const引用const属性
	int &h2 = const_cast<int &>(g2); //去掉const引用const属性
	printf("&g1=%#x\n", &g1);
	printf("&g2=%#x\n", &g2);

	printf("\n-----------------3.const的正确用法-------------------------\n");
	//正确用法： 去除原本就是非常量的const
	int i = 10;
	printf("before i =  %d\n", i);
	func(i);
	printf("after i =  %d\n", i);
	return 0;
}
