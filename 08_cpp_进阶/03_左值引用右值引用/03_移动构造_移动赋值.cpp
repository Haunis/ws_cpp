/**
 *	参考:
 * 		https://zhuanlan.zhihu.com/p/97128024
 * 		https://www.cnblogs.com/likaiming/p/9045642.html
 * 
 * 	带右值引用参数的拷贝构造又叫移动构造函数，如：Person(Person &&other)
 *	带右值引用参数的赋值重载函数又叫移动赋值函数，如：Person &operator=(Person &&other)
 * 
 *  右值引用的存在并不是为了取代左值引用，而是充分利用右值(特别是临时对象)的构造来减少对象构造和析构操作以达到提高效率的目的。
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
class Person
{
public:
	int *m_ptr; //带有堆内存的类，必须提供深拷贝构造函数

public:
	Person() : m_ptr(new int[3])
	{
		printf("Person 构造 this = %#x\n", this);
	}
	~Person()
	{
		delete[] m_ptr;
	}

	// 拷贝构造函数.此处为深拷贝构造函数
	// 带有堆内存的类必须提供深拷贝构造函数；因为默认的构造函数是浅拷贝，会发生“指针悬挂”问题，即m_ptr会被删除两次
	// 调用时机：1.Person p2=p1 2.函数参数为对象 3.函数返回对象（具体查看面向对象demo）
	Person(const Person &other) : m_ptr(new int[3])
	{
		std::copy(other.m_ptr, other.m_ptr + 3, m_ptr);
		printf("Person 复制构造 &other=%#x,this=%#x\n", &other, this);
	}

	// 移动构造函数. 和上面的拷贝构造函数是重载.
	// 拥有临时对象other的所有权,因为传入的是右值,调用处后续不会再用到该临时对象,称为移动语义
	// 无需拷贝动态资源
	Person(Person &&other) : m_ptr(other.m_ptr)
	{
		//因为传入的参数是右值,是临时的,所以可以直接置为空
		//源对象的指针应该置空，以免源对象析构时影响本对象
		printf("Person 移动构造 ,&other=%#x,this=%#x\n", &other, this);
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	//移动赋值函数
	Person &operator=(Person &&other)
	{
		printf("operator=\n");
		m_ptr = new int[3];
		std::copy(other.m_ptr, other.m_ptr + 3, m_ptr);
		return *this;
	}
};

void func(Person p)
{
	// do_something
	printf("func --> &p = %#x\n", &p);
}

int main()
{

	printf("\n--------------------1.调用复制构造----------------------\n");
	Person p;
	func(p); // 调用Person的拷贝构造函数来创建实参

	printf("\n--------------------2.调用移动构造函数 ----------------------\n");
	// gcc编译器会自动优化，不会调用复制构造和移动构造；要使用 -fno-elide-constructors 关闭优化
	func(Person());

	printf("\n--------------------3.move ----------------------\n");
	func(std::move(p)); //调用移动构造函数; 之后p就不可使用了，因为移动构造里把p.m_ptr置为空指针了

	printf("\n--------------------4.移动赋值函数 ----------------------\n");
	Person p4;
	*p4.m_ptr = 100;
	printf("*p4.m_ptr = %d\n", *p4.m_ptr);

	// Person p5 = std::move(p4);//调用移动构造函数（右值构造）
	Person p5;
	p5 = std::move(p4); //调用移动赋值函数
	printf("*p5.m_ptr = %d\n", *p5.m_ptr);
	return 0;
}
