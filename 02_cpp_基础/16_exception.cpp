/*
 *	参考:
 *		https://blog.csdn.net/qq_40707451/article/details/86675979
 *		https://blog.csdn.net/Outtch_/article/details/108554832
 *		https://www.cnblogs.com/findumars/p/4899060.html?utm_source=debugrun&utm_medium=referral
 *  Created on: 2019年3月11日
 *
 *	异常处理
 *		和Java异常处理相似都是try{}catch(){}
 *		不过，格式稍微有些不同，要用throw
 *		try{
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
#include <vector>
using namespace std;
class A
{
	virtual void fun() {}
};
void func_catch_char()
{
	try
	{
		int i = 0;
		if (i == 0)
		{
			throw "Out Of Range";
		}
	}
	catch (const char *str)
	{
		printf("throw str: %s\n", str);
	}
}

void func_catch_exception()
{
	try
	{
		vector<int> v = {1, 2, 3, 4, 5, 6};
		for (int cur = 0; cur <= v.size(); cur++)
		{
			cout << v.at(cur) << endl;
		}
		// A *a = NULL;
		// typeid(*a);
	}
	catch (std::exception &e)
	{
		cout << "catch std::exception : " << e.what();
	}
	catch (...)
	{ //捕获所有异常
		printf("catch all exception ... 未知异常\n");
	}
}

struct MyException : public exception
{
	const char *what() const throw()
	{
		return "myexception what\n";
	}
};

int main()
{
	printf("-------------1.catch char-----------------\n");
	func_catch_char();

	printf("\n-----------2.catch_exception-----------------\n");
	func_catch_exception();

	printf("\n-----------3.自定义异常-----------------\n");

	try
	{
		if (2 > 1)
			throw MyException();
	}
	catch (MyException err)
	{
		cout << err.what() << " xxxxxxx " << endl;
	}

	printf("\n----------------code end--------------------\n");
	return 0;
}
