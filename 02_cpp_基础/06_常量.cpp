/*
 * 	1.定义普通常量 const a = 100;
 *
 * 	2.宏常量 #define pi 3.14;
 *
 *  4.宏常量和const常量区别
 * 		参考：https://www.cnblogs.com/xumaomao/articles/11049541.html
 *
 *  	1.编译器处理不同：
 *  		宏定义是”编译时“概念，在预处理阶段展开，不能对宏定义调试。
 *  		const常量是”运行时“概念，程序运行时使用，类似于只读数据
 *		2.存储方式不同：
 *			宏定义直接替换，不分配内存；
 *			const需要分配内存
 *		3.类型和安全检查不同：
 *			宏定义是字符替换，没有数据类型区别，也没有类型安全检查，可能产生边际效益等错误
 *			const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查
 *		4.有效范围不同：
 *			宏常量在后面所有地方有效；
 *			const只在所在的函数内部有效
 *		5.定义后可否取消：宏常量可以通过#undef 取消；const常量在定义域永久有效
 *
 *	 define 不是代码语句，是预处理器指令，后面不需要加分号";"
 */

#include <iostream>
#include<stdio.h>
using namespace std;

#define MY_NAME "李三"  //宏常量定义
#define AAA 100

const int const_width = 200; //声明常量

void fun(int a){
	printf("fun --> a=%d\n",a);
}

int main()
{
	printf("\n--------------------1. const 常量-------------------------------\n");
	cout << "width : " << const_width << endl; //一般常量
	fun(const_width);

	printf("\n--------------------2. 宏常量-----------------------------------\n");
	cout << "MY_NAME : " << MY_NAME << endl;
	fun(AAA);
	

	return 0;
}
