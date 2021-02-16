/**
 * 参考:
 * 		https://zhuanlan.zhihu.com/p/54078587
 *		https://www.jianshu.com/p/b8d6b10da667
 *
 *	make_unique是c++14的特性
 *
 *	eclipse支持c++14:
 *		C/C++Build->Settings->GCC C++ Compiler->Miscellaneous->:  -std=c++14
 *		C/C++General->Paths And Symbols ->Symbols->GNC c++ ->:  __cplusplus  201402L
 *	
 *	auto_ptr:
 *		c++98方案，现已弃用；其实现和自定义指针2类似；
 *		允许直接使用赋值，如auto_p2 = auto_p1
 *		其缺点是：指针auto_p1转移对象使用权到auto_p2后，再使用auto_p1将会报错，存在潜在的内存崩溃
 * 
 *	std::unique_ptr：
 *		替换c++98的auto_ptr
 *		实现独占式拥有或严格拥有概念，保证同一时间内只有一个智能指针可以指向该对象。
 * 		它对于避免资源泄露(例如“以new创建对象后因为发生异常而忘记调用delete”)特别有用。
 *
 *	但是前提是该对象是建立在栈上的，千万不要使用动态分配的类对象，在堆上其行为与普通指针变得一样
 *	
 *	std::unique_ptr和自定义指针3很像了
 *
 *
 */

#include <iostream>
#include <memory> //unique_ptr
#include <stdio.h>
using namespace std;

class Person
{
public:
	Person()
	{
		printf("Person 构造 %#x\n", this);
	}
	virtual ~Person()
	{
		printf("Person 析构 -->%#x\n", this);
	}

public:
	virtual void func()
	{
		printf("person func...\n");
	}
	//重载操作符<<,作为友元函数可以访问类的私有成员
	friend std::ostream &operator<<(std::ostream &out, const Person &person)
	{
		out << "I am a Person" << endl;
		return out;
	}
};

// void usePerson(std::unique_ptr<Person> person)//error;std::unique_ptr作为形参时，不能发生拷贝
void usePerson(const std::unique_ptr<Person> &person)
{
	if (person)
	{
		cout << *person;
	}
}
int main()
{
	printf("------------------1.1 方式1初始化：make_unique<T>()---------------------\n");
	{
		//		auto ptr = std::make_unique<Person>();
		std::unique_ptr<Person> ptr = std::make_unique<Person>();
		usePerson(ptr); //可以作为左值传给函数,因为这样不会改变Person指针的所有权

		// std::unique_ptr<Person> ptr2 = ptr; //error;不允许左值赋值
		std::unique_ptr<Person> ptr2 = std::move(ptr); //调用了unique_ptr移动构造,转移了对象所有权?
		printf("ptr.get()=%#x\n", ptr.get());		   //0;已经转移指针控制权
		printf("ptr2.get()=%#x\n", ptr2.get());

		ptr2.get()->func();
	}
	printf("\n-----------------1.2 方式2初始化:ptr(T*)---------------------\n");
	{
		Person *pPerson = new Person();
		std::unique_ptr<Person> ptr(pPerson);
		// std::unique_ptr<Person> ptr2(pPerson);//error;不能使用一个资源初始化多个std:unique_ptr，会析构两次
		ptr.get()->func();
	}
	printf("\n-----------------2.realease---------------------\n");
	{
		std::unique_ptr<Person> ptr = std::make_unique<Person>();
		Person *pPerson = ptr.release(); //release不是释放内存的意思，是释放控制权，返回指针
		pPerson->func();
	}
	printf("----------------code end----------------\n");
	// cin.ignore(1);
	return 0;
}
