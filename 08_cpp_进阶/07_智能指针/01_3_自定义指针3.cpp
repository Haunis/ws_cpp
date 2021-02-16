/**
 * 参考:https://zhuanlan.zhihu.com/p/54078587
 *
 * 通过自定义智能指针,理解智能指针工作原理
 *
 * 对01_2的改进：
 * 		禁用复制构造函数和复制操作运算符,进行赋值，复制后操作后，原对象必须放弃指针所有权
 * 		指针只有一个ptr持有,和std::unique_ptr相似
 */
#include <iostream>
#include <stdio.h>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
using namespace std;

template <typename T>
class AutoPtr
{
public:
	T *m_ptr;

public:
	AutoPtr(T *ptr = nullptr) : m_ptr{ptr} //和 m_ptr(ptr)一样
	{
		printf("AutoPtr 构造,this=%#x, m_ptr=%#x\n", this, m_ptr);
	}

	AutoPtr(const AutoPtr &other) = delete; //禁用复制构造函数

	//移动构造函数：参数是右值引用的复制构造
	AutoPtr(AutoPtr &&other) : m_ptr(other.m_ptr) //将other存储的指针m_ptr赋值给本类m_ptr
	{
		other.m_ptr = nullptr;
		printf("AutoPtr 右值构造 this=%#x, &other=%#x\n", this, &other);
	}

	AutoPtr &operator=(const AutoPtr &other) = delete; //禁用复制操作运算符(等号右边不能是左值)

	//移动赋值函数：参数是右值引用的赋值函数
	AutoPtr &operator=(AutoPtr &&other) //赋值时，等号右边是右值
	{
		printf("AutoPtr赋值操作符 this=%#x,other=%#x \n", this, &other);
		if (this == &other)
		{
			return *this;
		}
		std::swap(m_ptr, other.m_ptr); //交换两个变量的值
		return *this;
	}

	virtual ~AutoPtr()
	{
		delete m_ptr;
	}

	T &operator*()
	{
		printf("op*** this=%#x ,m_ptr=%#x\n", this, m_ptr);
		return *m_ptr;
	}
	T *operator->()
	{
		printf("operator->... this=%#x ,m_ptr=%#x\n", this, m_ptr);
		return m_ptr;
	}

	bool isNull() const
	{
		return m_ptr == nullptr;
	}
};

class Person
{
public:
	string name;

public:
	Person()
	{
		printf("Person 无参构造 this=%#x\n", this);
	};
	Person(string name)
	{
		this->name = name;
		printf("Person 有参构造 this=%#x\n", this);
	};
	Person(const Person &other) //拷贝构造函数
	{
		this->name = other.name;
		printf("Person 无参构造 this=%#x，other=%#x\n", this, &other);
	};
	~Person()
	{
		printf("Person 析构... this=%#x\n", this);
	};
	void func()
	{
		printf("person func...\n");
	}
	virtual void funcVirtual()
	{
		printf("person funcVirtual ...\n");
	}
};

int main()
{
	printf("\n------------------1.调用移动构造函数-------------------\n");
	AutoPtr<Person> ap11(new Person);
	// AutoPtr<Person> ap12(ap11); //error;禁用了复制构造,所以此处会报错
	AutoPtr<Person> ap12(std::move(ap11));
	printf("ap11.m_ptr=%#x\n", ap11.m_ptr); //0
	printf("ap12.m_ptr=%#x\n", ap12.m_ptr);
	ap11->func(); //访问的是非虚函数，类里的函数；虽然可以访问，但是该行为是未定义行为，参考：面向对象delete demo
	// ap11->funcVirtual();//crash;虚函数是延迟绑定的，虚表指针被销毁后就不可以再访问了

	printf("\n------------------2.调用移动构赋值-------------------\n");
	AutoPtr<Person> ap21(new Person);
	// AutoPtr<Person> ap22 = ap21; //error;禁用了复制构造,所以此处会报错
	AutoPtr<Person> ap22;
	ap22 = std::move(ap21);
	printf("ap21.m_ptr=%#x\n", ap21.m_ptr); //0
	printf("ap22.m_ptr=%#x\n", ap22.m_ptr);
	ap21->func(); //不会crash，但是是未定义行为
	// ap21->funcVirtual();//crash

	printf("\n-------------------code end------------------\n");

	//	cin.ignore(10);
	return 0;
}
