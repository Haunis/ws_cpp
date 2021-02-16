/**
 *	友元类：在Person里定义friend Inner，则Inner是Person的友元类（记忆：内是外的友元类）
 *
 * 	作用：如果Inner持有Person的实例的话，Inner可以直接访问Person里的private，protected成员
 *
 * 	评论：感觉没啥用，可以参考java，直接在B里定义一个函数获取私有成员变量
 *
 */

#include <iostream>
#include <stdio.h>
using namespace std;

class Inner; //先声明，否则Person里无法使用Inner类

class Person
{
private:
	string name;

public:
	Person(string name)
	{
		this->name = name;
	}

public:
	friend Inner;	 //Inner是Person的友元类（内是外的友元类）
	string getname() //定义一个方法，可以直接访问私有成员；感觉友元类还是有点麻烦
	{
		return name;
	}
};

class Inner
{
public:
	string func(Person p)//友元类持有的类对象可以直接访问私有属性
	{
		return p.name;
	}
};

int main()
{
	Inner inner;
	Person p("lee0");

	// printf("name = %s\n", p.name.data());//error;不可直接访问私有成员

	printf("------------------1.使用get方式访问私有成员----------------------\n");
	string name = p.getname();
	printf("name = %s\n", name.data());

	printf("\n------------------2.使用友元类访问私有成员----------------------\n");
	name = inner.func(p);
	printf("name = %s\n", name.data());

	return 0;
}
