/**
 * 参考:https://zhuanlan.zhihu.com/p/54078587
 *	
 * 对01_1智能指针的改进：
 * 		调用了复制构造函数后原auto_ptr不再持有指针m_ptr,如果原auto_ptr后续要使用m_ptr会出错
 * 		c++11之前的std::auto_ptr就和这个相似
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
		printf("AutoPtr 构造, this=%#x\n", this);
	}

	//复制构造;转移指针所有权，原指针指向空
	//已实例化好的如ap22赋值给未初始化的ap11时调用，AutoPtr ap22=ap11;
	AutoPtr(AutoPtr &other)
	{
		printf("AutoPtr 拷贝构造, this=%#x,&other=%#x\n", this, &other);
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}

	//重载赋值操作符； 转移指针所有权，原指针指向空
	//实例对象赋值时调用，如ap11=ap22
	AutoPtr &operator=(AutoPtr &other)
	{
		printf("AutoPtr 操作符= ,this=%#x,&other=%#x\n", this, &other);
		if (&other == this)
			return *this;

		delete m_ptr;
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
		return *this;
	}

	T &operator*() //重载操作符*，返回m_ptr指向的实体对象
	{
		return *m_ptr;
	}
	T *operator->() //重载操作符->,使得指针的调用转换为m_ptr指针的调用
	{
		printf("op-> this=%#x ,m_ptr=%#x\n", this, m_ptr);
		m_ptr = nullptr;
		m_ptr->func();
		return m_ptr;
	}
	bool isNull() const
	{
		return m_ptr == nullptr;
	}
	virtual ~AutoPtr()
	{
		delete m_ptr;
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
		printf("person func ...this=%#x\n", this);
	}
};

int main()
{

	AutoPtr<Person> ap1(new Person);
	AutoPtr<Person> ap2(ap1);
	printf("ap1.m_ptr=%#x\n", ap1.m_ptr); //0；调用复制构造后,ap1.m_ptr被置为nullptr
	printf("ap2.m_ptr=%#x\n", ap2.m_ptr);

	//	cin.ignore(10);
	return 0;
}
