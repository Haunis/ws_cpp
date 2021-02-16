/**
 * 参考:https://www.cnblogs.com/rednodel/p/9299251.html
 *
 * 当类的构造函数只有一个参数如int时,可以用如下方式初始化:
 * 		方式1: A a {8}; //需要c++ 98支持
 * 		方式2: A a = 8;
 * 		看起来很奇怪,如果要防止方式2可使用 explicit修饰
 * 
 * explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的
 * 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式)
 */

#include <iostream>
#include <stdio.h>
using namespace std;
class Person
{
public:
	explicit Person(int age) //声明该构造是显式的，不可以Person p2 = 22这样初始化
	{
		printf("构造 called age=%d\n", age);
	}
};

int main()
{
	Person p1{11};
	// Person p2 = 22;//error;显式声明后,不可再这样使用
	return 0;
}
