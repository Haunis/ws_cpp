/*
 *  Created on: 2019年3月11日
 *  Author: BTI-PC
 *
 *	参考:
 *		https://blog.csdn.net/Bob__yuan/article/details/88044361
 *		https://www.cnblogs.com/qinguoyi/p/10303912.html
 *
 *	C语言中的强制类型转换:
 *		1.显式转换; 一般是用小括号强制转换,如 Type b = (Type) a
 *		2.隐式转换; 如 float f = 3.1425, int i = f这样的隐式转换
 *
 *	reinterpret_cast <type-id> (expression)：
 *		最鸡肋的转换函数，可以将任意类型转换为任意类型，因此非常不安全。
 *		只有将转换后的类型值转换回到其原始类型，这样才是正确使用reinterpret_cast方式。
 *		type-id:必须是一个指针、引用、算术类型、函数针或者成员指针
 *		
 *		是将一个指针的二进制数据复制到另外一个指针,对指针的内容不做任何检查或转换
 *		实际结果可能取决于编译器,因此是不可移植的
 *
 *	主要用途:
 *		1.改变指针或者引用的类型
 *		2.将指针或者引用转换成整型
 *		3.将整型转换成指针
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

int main()
{
	A *a = new A;
	B *b = reinterpret_cast<B *>(a);
	printf("a = %#x\n", a);
	printf("b = %#x\n", b); //a b 存储的地址相等
	b->b_name = "B Name";	//如果A中不定义string类型的变量b->b_name将无法赋值成功
	cout << b->b_name << endl;

	b->fun(); //可以执行成功

	//	int result_a = reinterpret_cast<int>(a);//error;精度不够,必须是long long或者long(linux64 long是8位)
	long long result_a = reinterpret_cast<long long>(a); //指针转换成长整型
	printf("result_a = %#x\n", result_a);

	return 0;
}
