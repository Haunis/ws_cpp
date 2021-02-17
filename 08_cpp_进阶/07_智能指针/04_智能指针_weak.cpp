/**
 * 参考:
 * 		https://zhuanlan.zhihu.com/p/54078587
 * 		https://www.cnblogs.com/WindSun/p/11444429.html
 *
 * std::weak_ptr<T> ptr不持有T的指针,就是没有T对象在堆内存的所有权
 *
 * std::weak_ptr<T> 可以通过lock()方法获取std::shared_ptr<T>,从而访问T对象
 * 
 * weak_ptr设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 
 * 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。
 * weak_ptr是用来解决shared_ptr相互引用时的死锁问题
 * 如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放
 *
 */
#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;

class Person
{
public:
	string name;
	// std::shared_ptr<Person> m_partner;//shared_ptr持有Person指针，导致循环引用，Person最后不会被析构
	std::weak_ptr<Person> m_partner; //不会持有Person指针,只是旁观者,使用的时候lock()可获取该对象的引用
public:
	Person(const string &name) : name{name}
	{
		printf("Person 构造 name=%s, this=%#x\n", name.data(), this);
	}

	virtual ~Person()
	{
		printf("Person 析构 --> name=%s, this=%#x\n", name.data(), this);
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
		{
			return false;
		}

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << "partnerUp... " << p1->name << " is now partenered with " << p2->name << endl;
		return true;
	}
};

int main()
{
	printf("-----------------1.循环引用-------------------\n");
	{
		auto p1 = std::make_shared<Person>("lee1");
		auto p2 = std::make_shared<Person>("lee2");
		partnerUp(p1, p2); // 互相设为伙伴

		string p1_partner_name = p1->m_partner.lock()->name;
		cout << "p1_partner_name=" << p1_partner_name << endl;
		printf("p1.user_count = %d\n", p1.use_count());
		printf("p2.user_count = %d\n", p2.use_count());
	}

	printf("\n-----------------2.‘自锁’-------------------\n");
	{
		auto p1 = std::make_shared<Person>("Lucy");
		partnerUp(p1, p1); //如果m_partner使用std::shared_ptr,p1和自己互为伙伴,自己持有自己的引用,导致不能析构
	}
	printf("\n----------------code end-------------------\n");

	//	cin.ignore(1);
	return 0;
}
