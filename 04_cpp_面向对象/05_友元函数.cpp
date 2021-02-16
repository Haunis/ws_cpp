/*
 *  Created on: 2019年3月6日
 *     Author: BTI-PC
 *
 * 	友元函数：就是普通函数在类里用friend修饰.如：friend string func(Person stu);
 * 
 * 	作用：友元函数持有的实例可以访问类里的private,protected成员
 * 	评论：感觉没啥用，参考java里，定义一个函数就可以获取私有成员变量。
 * 		不一定一定要instance.privateMember，可以instance.getPrivateMember();
 *
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Person
{
private:
	string name;

public:
	Person(string name);

public:
	//声明友元函数；普通函数持有的实例不可直接访问私有成员
	friend string func(Person stu);

	void setName(string str);
	string getname();
	string toString();
};
Person::Person(string name = "no_name") //默认name是"no_name"
{
	this->name = name;
}
void Person::setName(string name)
{
	this->name = name;
}
string Person::getname()
{
	return this->name;
}
string Person::toString()
{
	return "name : " + this->name;
}
string func(Person p) //友元函数
{
	return p.name; //友元函数可以访问类里的private,protect成员
}

int main()
{
	Person p("lee");

	printf("-------------------1.使用get的方式访问私有成员---------------------\n");
	// string name = p.name; //error;无法直接访问私有成员
	string name = p.getname(); //可以通过公有函数访问私有成员
	printf("p.name= %s\n", name.data());

	printf("-------------------2.使用友元函数的方式访问私有成员---------------------\n");
	string name2 = func(p);
	printf("name2= %s\n", name2.data());

	return 0;
}
