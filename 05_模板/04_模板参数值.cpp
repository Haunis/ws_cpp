/*
 *  Created on: 2019年3月8日
 *  	Author: BTI-PC
 *
 *	模板参数
 *
 *	template<>方括号里常用参数如下:
 *		template<class T>
 *		template<class T,class U>
 *		template<class T,int N>
 *		template<class T=char>//默认类型时char
 *		template<int Tfun(int)>//参数为一个函数
 */
#include <iostream>
using namespace std;
template <class T, int N>
class Array
{
public:
	T array[N]; //T类型的array,里面有N个元素
public:
	void set(int key, T value);
	T get(int key);
};

template <class T, int N>
void Array<T, N>::set(int key, T value)
{
	array[key] = value;
}

template <class T, int N>
T Array<T, N>::get(int key)
{
	return array[key];
}

int main()
{
	Array<string, 5> array;
	array.set(0, "Lee0");
	array.set(1, "Lee1");

	string result = array.get(1);
	cout << "result : " << result << endl;
	return 0;
}
