/**
 * 参考: https://blog.csdn.net/caoshangpa/article/details/79392878
 *
 * 如果一个对象被std::shared_ptr管理, 且该对象的类的继承std::enable_shared_from_this
 * 那么该类就有成员函数shared_from_this,该函数返回额外的std::shared_ptr,且与原std::shared_ptr共享对象所有权
 */
#include <memory>
#include <iostream>
#include <stdio.h>
using namespace std;
class Bad
{
public:
	std::shared_ptr<Bad> getptr()
	{
		return std::shared_ptr<Bad>(this);
	}
	~Bad()
	{
		printf("Bad ~Bad():%#x\n", this);
	}
};

struct Good: std::enable_shared_from_this<Good> // 注意：继承
{
public:
	std::shared_ptr<Good> getptr()
	{
		return shared_from_this();
	}
	~Good()
	{
		printf("Good:: ~Good():%#x\n", this);
	}
};

int main()
{
	printf("---------------1.错误示例--------------\n");
	// 错误的示例，每个shared_ptr都认为自己是对象仅有的所有者
	std::shared_ptr<Bad> bp1(new Bad());
	std::shared_ptr<Bad> bp2 = bp1->getptr();//std::shared_ptr<Bad>(this);
											 //相当于用同一个指针初始化了两次，会报错（会被析构两次）
	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl; //1
	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl; //1

	printf("\n-------------2.正确示例--------------\n");
	// 大括号用于限制作用域
	{
		std::shared_ptr<Good> gp1(new Good());
		std::shared_ptr<Good> gp2 = gp1->getptr();
		// 打印gp1和gp2的引用计数
		std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;//2
		std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;//2

	}
}
