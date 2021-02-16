/**
 * 	Created on: 2019年3月5日
 * 
 * 参考: https://zhuanlan.zhihu.com/p/54078587
 * 构造函数的参数有默认值：
 * 		Person::Person(string temp_name = "default_hhh", int temp_age = -1):
 * 							name{temp_name},
							age{temp_age}
							{}
 * 		该情况下不可再声明无参构造，因为Person p这样的初始化也可以调用有默认值的有参构造
 * 		这样就会产生二义性--不知道要调哪个构造函数
 *    
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Person
{
public:
	int age;
	string name;

public:
	Person(); // error;如果有参构造有默认值了，不可再声明无参构造
	Person(string name, int age); //有参构造
	~Person();

public:
	string toString(); //在类的内部无函数体，函数的具体实现可在外部写
};
//还可以这样初始化...
Person::Person(string temp_name = "default_hhh", int temp_age = -1) : name{temp_name},
																	  age{temp_age}
{
	this->name = name;
	this->age = age;
	printf("默认值的构造函数 --> this = %#x\n", this);
}
string Person::toString()
{
	return "name=" + name + ", age=" + to_string(age);
}
Person::~Person()
{
	printf("析构函数被调用 this = %#x\n", this);
}

int main()
{
	printf("---------------------1.构造函数不传参----------------------------\n");
	Person p1; //在有有参构造的情况下，实例化无参构造的对象时需要实现无参构造

	printf("p1: %s\n", p1.toString().data());

	printf("\n-------------------2.构造函数传参----------------------------\n");
	Person p2("lee2", 18);					//引用类型
	printf("sizeof(p2): %d\n", sizeof(p2)); //40;类的大小取决于成员变量
	printf("p2 : %s\n", p2.toString().data());

	return 0;
}
