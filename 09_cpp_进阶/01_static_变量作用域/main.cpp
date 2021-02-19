/*
 *  Created on: Mar 25, 2020
 *	Author: haunis
 *
 *  参考：
 * 		https://www.cnblogs.com/yongy1030/p/7359009.html
 *  	https://blog.csdn.net/yunyun1886358/article/details/5632087
 *
 *	static有两种用法：
 *		面向过程的static和面向对象的static,本demo是面向过程的static
 * 		https://blog.csdn.net/legend_hua/article/details/78193239
 * 
 *  1.全局变量：
 * 		全局有效；程序运行期一直存在；存储在全局数据区
 *
 *  2.全局静态变量：
 * 		文件作用域（只在被定义的文件可见，不可被extern修饰）;程序运行期一直存在；存储在全局数据区
 *  	定义：1.const int a ;  2. const static int a; 3.static int a
 *
 *  3.静态局部变量：
 * 		局部作用域有效；程序运行期一直存在；存储在全局数据区
 *  	只被初始化一次，多线程中使用要加锁
 * 
 *  4.局部变量：
 * 		局部作用域；程序运行出局部作用域即被销毁；存储在栈区
 *
 *  5.局部变量和全局变量可以重名. 重名后默认使用局部变量,要想访问全局变量要使用域限定符"::"
 *
 *  声明不分配内存空间,定义分配内存空间
 *  变量可以声明多次,但只能定义一次
 */
#include <stdio.h>
#include "var.h"
int g_count = 0;		 //全局变量
extern int g_var;		 //表明该变量是在别的地方定义
extern int g_static_var; //表明该变量是在别的地方定义，虽然声明了，但是该文件无法访问

int g_temp = g_count; //c++ ok;但c语言不行，c语言初始化变量时不能用其他变量赋值，只能用常量赋值

void fun()
{
	int inner_count = 0;
	static int inner_static_count = 0; //局部静态变量，函数调用后保留原值,只是保留其生命周期，不会改变其作用域

	inner_count++;
	inner_static_count++;
	g_count++;
	printf("inner_count = %d, inner_static_count=%d,g_count=%d\n", inner_count, inner_static_count, g_count);
}

int main(int argc, char *argv[])
{
	printf("----------------1.访问别的文件定义的全局变量---------------------\n");
	printf("g_var = %d, &g_var=%#x\n", g_var, &g_var);

	printf("\n---------------2.访问别的文件定义的静态全局变量---------------------\n");

	// printf("g_static_var = %d\n",g_static_var);//error,无法访问

	printf("\n---------------3.局部变量和全局变量重名---------------------\n");
	int g_var = 200; //和全局变量重名
	printf("g_var = %d, &g_var=%#x\n", g_var, &g_var);
	printf("::g_var=%d,&::g_var=%#x\n", ::g_var, &::g_var); //使用域限定符访问全局变量
	//	printf("global_static_int = %d", g_static_var);

	printf("\n---------------4.函数内部的静态变量---------------------\n");
	fun();
	fun();
	fun();
}
