/*
 *	函数模板：相当于Java里的泛型
 *
 *	定义格式：
 *		在函数前面加template<class T>，如下1和2：
 *		1. template<class T> T function(T t){} //function前的T为返回值类型
 *		2. template<typename T>T function(T t){}
 *
 *
 */
#include<iostream>
#include<stdio.h>
using namespace std;

// template<class T> //ok
template<typename T> 
T getMax(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}

int main()
{
	int a = 3, b = 4, max1;
	long long c = 8, d = 9, max2;

	max1 = getMax<int>(a, b);
//	max1 = getMax(a, b);//ok
	max2 = getMax<long long>(c, d);
//	max2 = getMax(c, d);//ok
	printf("%d, %d which is bigger? %d\n", a, b, max1);
	printf("%lld, %lld which is bigger? %lld\n", c, d, max2);

	return 0;
}

