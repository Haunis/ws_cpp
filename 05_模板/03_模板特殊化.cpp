/*
 *	Created on: 2019年3月8日
 *	Author: BTI-PC
 *
 *	模板特殊化：
 *		就是模板类template<class T> class Pair T有具体类型时，如int时，做特殊处理
 *		当特殊化模板的一个具体pattern类型时，需要重新定义类的成员特殊化实现
 *
 *	特殊化模板也是模板的一部分
 *
 */
#include <iostream>
using namespace std;

//模板类
template <class T>
class Pair
{
	T value1, value2;

public:
	Pair(T t1, T t2) //构造函数
	{
		value1 = t1;
		value2 = t2;
	}

public:
	T func();
};
//模板类函数的通用实现，返回-1
template <class T>
T Pair<T>::func() //Pair<T>要跟T，否则编译通不过
{
	return -1;
}

///////////////////////////模板特殊化///////////////////////////////////////////////
//模板类接收的“泛型”为int，可以为类的函数实现使用特殊的实现
//特殊化模板也是模板的一部分，因为pattern有具体的类型所以template<>反括号里不需要指定类型
//和正常模板类书写区别：1.类前面不是template<class T>而是template<> 2.类后面跟具体类型如<int>
template <>
class Pair<int>
{
	int value1, value2;

public:
	Pair(int t1, int t2)
	{
		value1 = t1;
		value2 = t2;
	}

public:
	int func();
};

//特殊的实现
// template <class T> //error;不需要这行代码了
int Pair<int>::func()
{
	return value1 * value2;
}

int main()
{
	Pair<float> pair1(14.0, 3.0);
	Pair<int> pair2(14.0, 3.0);
	cout << "float  " << pair1.func() << endl;
	cout << "int " << pair2.func() << endl;

	return 0;
}
