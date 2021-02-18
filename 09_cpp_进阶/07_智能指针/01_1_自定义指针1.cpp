/**
 * 参考:https://zhuanlan.zhihu.com/p/54078587
 *
 * 通过自定义智能指针,理解智能指针工作原理
 *
 * 主要是利用栈上的对象离开作用域后,会自动销毁并清理(自动调用对象的析构函数)
 * 
 * 该智能指针缺点：
 * 		多个AutoPtr持有同一个m_ptr,导致m_ptr指向的对象被析构多次,会报错
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
	AutoPtr(T *ptr = nullptr) : m_ptr{ptr}
	{
		printf("AutoPtr构造: m_ptr=%#x\n", ptr);
	}

	virtual ~AutoPtr()
	{
		delete m_ptr;
	}

	T &operator*() //重载操作符 *；返回对象的引用，参考左引用demo
	{
		return *m_ptr;
	}
	T *operator->() //重载操作符->； 返回T*
	{
		return m_ptr;
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
		printf("person func ...\n");
	}
};

int main()
{
	AutoPtr<Person> ap1(new Person);
	AutoPtr<Person> ap2(ap1); //默认调用AutoPtr复制构造函数，会和ap1.m_ptr指向同一个Person,所以Person会被析构两次
	printf("ap1.m_ptr=%#x\n", ap1.m_ptr);
	printf("ap2.m_ptr=%#x\n", ap2.m_ptr); //ap1和ap2的m_ptr指向同一个Persons

	ap1->func();
	ap2->func(); //使用起来都没问题，但是会被析构两次，导致最终报错
	cout << "-------------end---------------" << endl;
	//	cin.ignore(10);
	return 0;
}
