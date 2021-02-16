/*
 *
 *	参考:
 *		https://blog.csdn.net/qq_40707451/article/details/86675979
 *		https://blog.csdn.net/Outtch_/article/details/108554832
 *  Created on: 2019年3月11日
 *
 *	异常处理
 *		和Java异常处理相似都是try{}catch(){}
 *		不过，格式稍微有些不同，要用throw
 *		try{
 *
 *			throw "Out of range";
 *		}catch(const* str){
 *			cout<<str<<endl;// Out of range
 *		}
 *
 *	此异常处理规则:
 *		1.抛出的异常类型必须和相应捕获异常的类型一致才能被捕获
 *		2.catch(…)可以捕获任意类型的异常。
 *		std::exception	该异常是所有标准 C++ 异常的父类。
 *
 */
#include <iostream>
#include <typeinfo>
#include <exception>
#include <stdio.h>
using namespace std;

void catch_char();
void catch_exception();
class A
{
	virtual void fun()
	{
	}
};
int main()
{
	printf("-------------1.catch_char-----------------\n");
	catch_char();

	printf("\n-------------2.catch_exception-----------------\n");
	catch_exception();

	return 0;
}
void catch_char()
{
	char charArray[10];
	try
	{
		for (int i = 0; i <= 10; i++)
		{
			if (i == 10)
			{
				throw "Out Of Range";
			}
			charArray[i] = 'a';
		}
	}
	catch (const char *str)
	{
		printf("throw str: %s\n", str);
	}
}
void catch_exception()
{
	try
	{
		cout << "call testTypied " << endl;
		A *a = NULL;
		typeid(*a);
	}
	catch (std::exception &e)
	{
		cout << "catch_exception : " << e.what() ;
	}
	catch (...)
	{ //捕获所有异常
		printf("catch_exception 未知异常\n");
	}
}
