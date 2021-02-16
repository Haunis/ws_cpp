/**
 * 参考:https://zhuanlan.zhihu.com/p/54078587
 *
 * std::weak_ptr<T> ptr不持有T的指针,就是没有T对象在堆内存的所有权
 *
 * std::weak_ptr<T> 可以通过lock()方法获取std::shared_ptr<T>,从而访问T对象
 *
 */
#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;

class Person
{
public:
	Person(const string &name) :
			m_name
			{ name }
	{
		printf("构造被调用 m_name=%s, this=%#x\n", m_name.data(), this);
	}

	virtual ~Person()
	{
		printf("析构被调用----> m_name=%s, this=%#x\n", m_name.data(), this);
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
		{
			return false;
		}

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << p1->m_name << " is now partenered with " << p2->m_name << endl;
		return true;
	}
	void printPartnerName()
	{
//		string partner_name = m_partner->getName();//m_partner是std::shared_ptr时
		string partner_name = m_partner.lock()->getName(); //m_partner 是std::weak_ptr时
		printf("%s 's partner is : %s \n", this->getName().data(), partner_name.data());
	}
	string getName()
	{
		return this->m_name;
	}
private:
	string m_name;
//	std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner; //不会持有Person指针,只是旁观者,使用的时候lock()可获取该对象的引用
};

int main()
{
	{
		auto p1 = std::make_shared<Person>("Lucy");
		auto p2 = std::make_shared<Person>("Ricky");
		partnerUp(p1, p2);  // 互相设为伙伴

		p1->printPartnerName();
	}

//	{
//		auto p1 = std::make_shared<Person>("Lucy");
//		partnerUp(p1, p1); //和自己互为伙伴,自己持有自己的引用,导致不能析构
//	}
	printf("-----------------------------------\n");
	//此时Person已被析构
//	cin.ignore(1);
	return 0;
}
