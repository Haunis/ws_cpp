/*
 *  Created on: 2019年3月11日
 *
 *	static_cast<type-id> (expression)：
 *		静态转换，编译时检查
 *		四类中最常见的,相当于C语言中的强制转换,把 expression 转换为 type-id 类型，但没有运行时类型检查来保证转换的安全性
 *		不能实现普通指针数据（空指针除外）的强制转换，一般用于父类和子类指针、引用间的相互转换。
 *
 *	主要用途:
 *		1.用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
 *      	1).进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
 *      	2).进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
 *   	2.用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。这种转换的安全性也要开发人员来保证。
 *  	3.把空指针转换成目标类型的空指针。
 *		4.把任何指针类型转换成空指针类型
 *   	5.把任何类型的表达式转换成void类型
 *
 *   注意：
 *   	1.static_cast不能转换掉expression的const、volatile、或者__unaligned属性
 *   	2.无继承关系的类型,不可转换,不支持类之间交叉转换
 *
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
public:
	string a_name;
};
class B
{
public:
	string b_name;
	void fun()
	{
		printf("B fun() called \n");
	}
};

class Fu
{
public:
	void fun()
	{
		printf("Fu fun ...\n");
	}
};
class FuVirtual
{
public:
	virtual void fuVirtualFun()
	{
		printf("fuVirtualFun ... \n");
	}
	virtual ~FuVirtual() //因为有虚函数,所以要用虚析构函数
	{
	}
};
class Zi : public Fu, public FuVirtual
{
public:
	void fun()
	{
		printf("zi fun ...\n");
	}
};
int main()
{

	printf("----------------1.将一个基类转换为一个子类类型------------------\n");
	//无动态类型检查,不安全
	Fu *pFu = new Fu;
	Zi *pZi = static_cast<Zi *>(pFu); //向下转型(将父类指针转换成子类指针),不安全
	pZi->fun();						  //zi fun

	//	B *b = static_cast<B*>(a); //error.无继承关系的类型,不可转换,不支持类之间交叉转换

	printf("\n----------------2.基本类型转换------------------\n");
	double d = 3.1415926;
	int i = d; //基本类型转换
	printf("C 隐式类型转换 d=%lf, 转换后i=%d\n", d, i);

	int i2 = static_cast<int>(d); //使用static_cast进行转换
	printf("使用 static_cast转换 i2=%d\n", i2);

	printf("\n----------------3.任意指针转换成auto指针------------------\n");

	const int i3 = 1;
	const int *i3_p = &i3;								 //常量指针,指针指向的内容不可修改
	const auto *auto_p = static_cast<const int *>(i3_p); //ok, auto是c++11特性
	// int *auto_p2 = static_cast<const int *>(i3_p);//error,无法转换掉expression的const、volatile、或者__unaligned属性

	return 0;
}
