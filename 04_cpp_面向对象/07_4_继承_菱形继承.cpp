/*
 *  Created on: 2019年3月6日
 *
 * 	多个父类存在同名函数,使用域限定符访问：
 * 		 zi.Fu1::fuFun();
 *
 *	参考：https://www.cnblogs.com/lsh123/p/7912623.html
 *	菱形继承：
 *		多个父类继承同一个基类,会引二义性和发数据冗余；
 *		二义性：多个父类含有一个同名方法
 *		数据冗余：父类的父类的成员变量会有多份;
 *				子类对象会包含父类成员变量，所以父类的成员变量会有两份
 *
 *	解决二义性：使用域限定，zi.Fu1::ancestorFun();
 *	解决数据冗余：使用虚继承
 *	
 *	虚继承如何解决数据冗余:不再保存父类内容,而是保存了一份偏移地址,将原始父类数据保存在一个公共位置
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class Ancestor
{
public:
	int age;

public:
	Ancestor()
	{
		printf("Ancestor: &age=%#x\n", &age); //如果不使用虚继承，age会有两份
	}

public:
	void ancestorFun()
	{
		printf("ancestorFun called \n");
	}
};
class Fu1 : virtual public Ancestor //使用虚继承解决二义性和数据冗余
{
public:
	void eat(string food)
	{
		cout << "fu1 eat : " << food << endl;
	}
};

class Fu2 : virtual public Ancestor
{
public:
	void eat(string food)
	{
		cout << "fu2 eat : " << food << endl;
	}
};
class Zi : public Fu1, public Fu2
{
};

int main()
{
	Zi zi;

	printf("----------------1.域限定符访问不同父类同名成员-------------------\n");
	// zi.eat("chicken"); //error;同名函数会引起歧义
	zi.Fu1::eat("fu1 chicken");
	zi.Fu2::eat("fu2 noodles");

	printf("----------------2.访问父类的父类的成员-------------------\n");
	zi.Fu1::ancestorFun();	 //不使用虚继承情况下,要使用域限定符来访问基类
	int ziAge = zi.Fu1::age; //不使用虚继承情况下,要使用域限定符来访问基类
	printf("ziAge = %d\n", ziAge);

	zi.ancestorFun(); //使用虚继承之后可以直接使用基类成员
	int ziAge2 = zi.age;
	printf("ziAge2 = %d\n", ziAge2);
	return 0;
}
