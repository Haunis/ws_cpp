/**
 * 参考:
 * 		https://zhuanlan.zhihu.com/p/54078587
 * 		https://www.cnblogs.com/WindSun/p/11444429.html
 *
 *	std::shared_ptr需要c++11支持
 *  使用code Runnr(右键或者右上角三角形运行)会无法运行，使用f6或者手动编译运行
 * 
 *	std::shared_ptr与std::unique_ptr的主要区别:
 *		1.std::shared_ptr是使用引用计数的智能指针。
 *			引用计数的智能指针可以跟踪引用同一个真实指针对象的智能指针实例的数目。
 *			这意味着，可以有多个std::shared_ptr实例可以指向同一块动态分配的内存，
 *			当最后一个引用对象离开其作用域时，才会释放这块内存。
 *		2.std::shared_ptr不能用于管理C语言风格的动态数组
 *			C++17以后，shared ptr可以管理C风格数组
 *
 *	因为重载了操作符"->",所以std::shared_ptr<T> ptr 可以通过"->"访问对象T
 * 	通过ptr和通过ptr.get()使用对象是等价的
 *	
 *	常用函数：
 *		ptr.get():获取指向对象T的指针
 *		ptr.use_count(): 查看有多少个std::shared_ptr<T>对象指向这个共享的T对象
 *		unique 返回是否是独占所有权( use_count 为 1)
 *		reset 放弃内部对象的所有权或拥有对象的变更, 会引起原有对象的引用计数的减少
 *		swap 交换两个 shared_ptr 对象(即交换所拥有的对象)
 *
 *
 */
#include <iostream>
#include <stdio.h>
#include <memory>
using namespace std;

class Person
{
public:
	string name;

public:
	Person(string name = "no name") : name(name)
	{
		printf("Person 构造, this=%#x\n", this);
	}
	virtual ~Person()
	{
		printf("Person 析构-->, this=%#x\n", this);
	}

	friend std::ostream &operator<<(std::ostream &out, const Person &pPerson)
	{
		out << "I am a Person" << endl;
		return out;
	}
	virtual void func()
	{
		printf("Person func ...\n");
	}
};

int main(int argc, char *argv[])
{
	printf("------------------1.1 方式1初始化：std::make_shared<T>()-------------------\n");
	{
		//	auto ptr1 = std::make_shared<Person>();
		std::shared_ptr<Person> ptr1 = std::make_shared<Person>();					   //都可以
		printf("ptr1.get()=%#x, ptr1.use_count()=%d\n", ptr1.get(), ptr1.use_count()); //1
		{
			printf("\n--------start------\n");
			auto ptr2 = ptr1; // 通过复制构造函数使两个对象管理同一块内存
			std::shared_ptr<Person> ptr3;	 // 初始化为空
			ptr3 = ptr1;	 // 通过赋值，共享内存
			printf("ptr1.get()=%#x, ptr1.use_count()=%d\n", ptr1.get(), ptr1.use_count()); //3
			printf("ptr2.get()=%#x, ptr2.use_count()=%d\n", ptr2.get(), ptr2.use_count()); //3
			printf("ptr3.get()=%#x, ptr3.use_count()=%d\n", ptr3.get(), ptr3.use_count()); //3
			printf("--------end------\n");
		}

		// 此时ptr2与ptr3对象析构了,只有ptr1持有Person的指针
		printf("ptr1.get()=%#x, ptr1.use_count()=%d\n", ptr1.get(), ptr1.use_count()); //1
		std::shared_ptr<Person> ptr2 = std::make_shared<Person>(); //会new一个Person,和ptr1里Person指针无关系
		printf("ptr1.get()=%#x, ptr1.use_count()=%d\n", ptr1.get(), ptr1.use_count()); //1；还是1

		ptr1->func();
		ptr1.get()->func(); //二者使用等价
	}

	printf("\n------------------1.2 方式2初始化：ptr(T*)-------------------\n");
	{
		/*
		std::shared_ptr与std::unique_ptr内部实现机理有区别，前者内部使用两个指针，
		一个指针用于管理实际的指针，另外一个指针指向一个”控制块“，其中记录了哪些对象共同管理同一个指针
		这是在初始化完成的，所以如果单独初始化两个对象，尽管管理的是同一块内存，它们各自的”控制块“没有互相记录的。 
		所以，use_count是1。
		但是如果是使用复制构造函数还有赋值运算时，“控制块”会同步更新的，这样就达到了引用计数的目的。
		
		使用std::make_shared进行初始化就不会出现该问题，所以要推荐使用
	*/

		Person *pPerson = new Person;
		// std::shared_ptr<Person> ptr21(pPerson);//ok;这样也能初始化
		std::shared_ptr<Person> ptr21{pPerson};
		printf("ptr1.get()=%#x, ptr21.use_count()=%d\n", ptr21.get(), ptr21.use_count()); //1

		std::shared_ptr<Person> ptr22{pPerson};  //运行时报错，不可以使用同一个指针初始化，会导致对象被析构两次
		printf("ptr1.get()=%#x, ptr22.use_count()=%d\n", ptr22.get(), ptr22.use_count()); //1
	}
	printf("\n----------------code end----------------\n");

	//	cin.ignore(1);
	return 0;
}
