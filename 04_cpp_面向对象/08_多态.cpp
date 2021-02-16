/*
 *参考:https://www.cnblogs.com/zkfopen/p/11061414.html
 *
 *	多态:
 *		父类指针指向子类地址;
 *		该父类指针可以调用被子类重写的函数(父类函数被virtual修饰,方可被子类重写)
 *
 *
 *	virtual作用：
 *		在使用基类指针指向子类对象地址的时候，如果子类重写了父类的函数
 *		则该指针调用函数时,是调用子类函数
 *
 *	动态联编:
 *		如果子类重写了父类的虚函数,当父类指针指向子类对象时(如Fu *fu = &zi),
 *		父类指针根据赋给他的不同子类指针,动态地调用子类函数而不是父类函数.
 *		这样的函数调用发生在运行阶段,而不是编译阶段,称为动态联编
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;

class Fu //抽象基类(有纯虚拟函数)，不用abstract修饰
{
protected:
	// virtual int area; //不可以使用virtual修饰成员变量
	// public:
	// 	virtual ~Fu() //析构函数，一个类仅有一个;因为有虚函数,所以要用虚析构函数
	// 	{
	// 		printf("fu 析构函数 this=%#x\n", this);
	// 	}

public:
	void func1() //正常函数,不可以被子类重写;,父类指针调用的还是父类的方法
	{
		printf("Fu func1 ...\n");
	}
	virtual void func2() //普通虚拟函数，可被重写
	{
		printf("fu func2 ...\n");
	}
	virtual void func3() = 0; //纯虚拟函数,必须被子类重写
};

class Son : public Fu
{
public:
	void func1()
	{
		printf("son func1 ...\n");
	}
	// void func2() //ok,重写父类函数时可以不用virtual关键字
	virtual void func2()
	{
		printf("son func2 ...\n");
	}
	void func3()
	{
		printf("son func3 ...\n");
	}
};

int main()
{
	// Fu fu; //errro;抽象基类不可以实例化，但可以定义指向它的指针

	// Fu *pFu_son = new Son;//ok
	Son son;
	Fu *pFu_son = &son; //父类指针指向子类，即为多态

	pFu_son->func1(); //父类func1是普通函数未被重写,调用父类函数
	pFu_son->func2(); //调用子类函数
	pFu_son->func3(); //调用子类函数
	return 0;
}
