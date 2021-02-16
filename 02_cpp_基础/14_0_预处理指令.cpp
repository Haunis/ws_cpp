/*
 *
 *  Created on: 2019年3月12日
 *
 * 	参考： 
 * 		https://www.cnblogs.com/spring-hailong/p/6095254.html
 * 		https://blog.csdn.net/weixin_36229332/article/details/53055657
 * 
 *	预处理指令：
 * 		以"#"开头，不做语法检查
 *	
 *	常用的预处理指令包括：
 *		宏定义：#define
 *		文件包含：#include
 * 		条件编译：#if、#elif、#ifndef、#ifdef、#endif、#undef
 * 		错误信息指令：#error
 * 		#line指令
 * 		布局控制：#pragma
 *
 */
#define MAX_WIDTH 100 //宏定义

//----------------1.#ifdef----------------------
#ifdef MAX_WIDTH //条件编译
#undef MAX_WIDTH
#endif

//-----------------2.#ifndef---------------------
#ifndef MAX_WIDTH
#define MAX_WIDTH 200
#endif
//-----------------3.#if--------------------
#if MAX_WIDTH > 100
#undef MAX_WIDTH //如果已经define,后面再define的话，要进行undef
#define MAX_WIDTH 300

#elif MAX_WIDTH < 50
#undef MAX_WIDTH
#define MAX_WIDTH 50

#else
#undef MAX_WIDTH
#define MAX_WIDTH 150

#endif

//-----------------3.#if--------------------
#ifdef __cplusplus //如果定义了__cpluscplus(即如果是.cpp文件，cpp文件默认定义了该宏)
#define HELLO (8)
#endif //endif __cplusplus


#include <iostream>
#include <stdio.h>
using namespace std;
void test_fun(int x, int y);
void test_fun2();
#define TEST_FUN(x, y) test_fun(x, y) //宏可以指向一个函数
#define TEST_FUN2 test_fun2

int main()
{

	cout << "MAX_WIDTH ----> " << MAX_WIDTH << endl;
	cout << "HELLO ------> " << HELLO << endl;

	if (200 == MAX_WIDTH)
	{
		printf("200 == MAX_WIDTH : true  \n");
	}

	cout << "__cplusplus : " << __cplusplus << endl; //大于或等于199711L
	cout << "__TIME__ : " << __TIME__ << endl;		 //文件编译的时间
	cout << "__DATE__ : " << __DATE__ << endl;		 //文件编译的日期
	cout << "__LINE__ : " << __LINE__ << endl;		 //当前行号
	cout << "__STDC__ : " << __STDC__ << endl;		 //如果编译器遵循ANSI C,其值为1，否则未定义。
	cout << "__FILE__ : " << __FILE__ << endl;		 //进行编译的源文件

	// cout<<"__VA_ARGS__"<<__VA_ARGS__<<endl;//error

	return 0;
}
