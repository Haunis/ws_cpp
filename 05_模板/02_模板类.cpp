/*
 *	模板类：对应Java里的泛型类
 *
 *	模板类写法：
 *		在class前面加 template<class T> 
 *		如：template<class T> class Demo{};
 *
 *	模板类函数定义的写法：template<class T> T Demo::fun(){};//Demo前的T为函数返回值类型
 *
 */

#include <iostream>
#include <stdio.h>
using namespace std;

//模板类
template <class T>
class Pair
{
private:
	T value1, value2;

public:
	Pair(T t1, T t2) //构造函数
	{
		value1 = t1;
		value2 = t2;
	}

public:
	T getMax();
};

//模板类定义的方法，在正常定义的函数前面加上template<class T>，Pair加上<T>即可
template <class T>	//这行代码必须写
T Pair<T>::getMax() //Pair后面要加<T>，否则编译通不过
{
	T temp;
	temp = value1 > value2 ? value1 : value2;
	return temp;
}

class Zi : public Pair<int> //子类继承时,指定模板父类具体的类型
{
public:
	Zi(int x, int y) : Pair(x, y)
	{
	}
};

int main()
{
	Pair<int> myPair(5, 7); //定义的时候,类名后面要在方括号里加具体类型
	int max = myPair.getMax();
	cout << "max = " << max << endl;

	Zi zi(3, 4);
	printf("zi.getMax() = %d\n", zi.getMax());
	return 0;
}
