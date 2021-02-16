/*
 *  Created on: 2019年3月11日
 *
 *	参考:
 *		https://blog.csdn.net/Bob__yuan/article/details/88044361
 *		https://www.cnblogs.com/qinguoyi/p/10303912.html
 *
 *  dynamic_cast<type-id> (expression):
 *  	expression:必须是引用或指针,转换成功的话返回指向类的引用或指针,转换失败则返回nullptr.
 *  	只能用于类间转换,支持类间交叉转换
 * 		特点：
 *  	1.其他三种都是编译时完成的，dynamic_cast 是运行时处理的，运行时要进行类型检查。
 * 		2.不能用于内置的基本数据类型的转换
 *  	3.无继承关系的类之间也可以相互转换，类之间的交叉转换。
 *  	4.如果dynamic_cast转换目标是指针类型并且失败了，则结果为nullptr
 *  	  如果转换目标是引用类型并且失败了，则将抛出一个std::bad_cast异常
 *  	5.在类层次间进行上行转换:
 * 		  即子类指针转化父类指针，dynamic_cast 和 static_cast 的效果是一样的。
 * 		  该转换是安全的
 * 		6.在类层次间进行下行转换
 *  	  即父类指针转化为子类指针，dynamic_cast 具有类型检查的功能，比 static_cast 更安全。
 *		  基类中一定要有虚函数，否则编译不通过。
 *		  基类中存在虚函数，就说明它有想要让基类指针或引用指向派生类对象的情况，此时转换才有意义。
 *  	  这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表中，只有定义了虚函数的类才有虚函数表
 *  	  向下转换的成功与否还与将要转换的类型有关，即要转换的指针指向的对象的实际类型与转换以后的对象类型一定要相同，否则转换失败。
 * 		
 *  	  在C++中，编译期的类型转换有可能会在运行时出现错误，特别是涉及到类对象的指针或引用操作时，更容易产生错误。
 *  	  dynamic_cast操作符则可以在运行期对可能产生问题的类型转换进行测试。
 *  	
 *
 *	总结:尽量少使用转型操作，尤其是dynamic_cast，耗时较高，会导致性能的下降，尽量使用其他方法替代
 *
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
public:
	string a_name;
	virtual void func() {}
};
class B
{
public:
	string b_name;
	void fun()
	{
		printf("b fun ... \n");
	}
};

class Fu
{
public:
	void fun()
	{
		printf("fu fun ...\n");
	}
};
class FuVirtual
{
public:
	virtual void fuVirtualFun()
	{
		printf("FuVirtual fuVirtualFun ... \n");
	}
	virtual ~FuVirtual() //因为有虚函数,所以要用虚析构函数
	{
	}
};
class Zi : public Fu, public FuVirtual
{
public:
	void fun()
	{
		cout << "zi fun ..." << endl;
	}
	void fuVirtualFun()
	{
		cout << "zi fuVirtualFun ..." << endl;
	}
};

int main()
{

	printf("\n---------------1.1 引用：上行转换-------------------------\n");
	//将子类转换为父类，安全的
	Zi zi;
	Fu fu = dynamic_cast<Fu &>(zi);
	fu.fun(); //Fu fun..

	FuVirtual fuv = dynamic_cast<FuVirtual &>(zi);
	// fuv.fun();//error；编译时报错，FuVirtual无fun()函数
	fuv.fuVirtualFun();

	printf("\n---------------1.2 引用：下行转换-------------------------\n");
	//将父类转换为子类,转换失败。。。
	Fu fu3;
	// Zi zi3 = dynamic_cast<Zi &>(fu3);//error;编译是报错，下行转换时，基类必须有虚函数
	FuVirtual fuv3;
	// Zi zi3 = dynamic_cast<Zi &>(fuv3);//error;运行是报错，抛出一个std::bad_cast异常

	printf("\n---------------2.1 指针：上行转换-------------------------\n");
	//子类指针转换成父类指针，安全的
	Zi *p_zi = new Zi;
	Fu *p_fu = dynamic_cast<Fu *>(p_zi);				//ok;向上转型安全
	p_fu->fun();										//fu fun...
	FuVirtual *p_fuv = dynamic_cast<FuVirtual *>(p_zi); //ok;向上转型安全
	p_fuv->fuVirtualFun();

	printf("\n---------------2.2 指针：下行转换-------------------------\n");
	//父类指针转换成子类指针,父类必须有虚函数
	Fu *p_fu22 = new Fu;
	// Zi *p_zi22 = dynamic_cast<Zi *>(p_fu22); //error;父类必须有虚函数

	FuVirtual *p_fuv22 = new FuVirtual;
	Zi *p_zi22 = dynamic_cast<Zi *>(p_fuv22); //ok,
	p_zi22->fun();							  //zi fun ...
	// p_zi22->fuVirtualFun();//error;TODO：待找到原因

	printf("\n---------------3. 多态指针：下行转换-------------------------\n");
	//父类类型指向子类的指针，转换成子类指针，父类必须有虚函数
	Fu *p_fu_zi = new Zi;
	// Zi *p_ret = dynamic_cast<Zi *>(p_fu_zi);//error;父类无虚函数

	FuVirtual *p_fuv_zi = new Zi;
	Zi *p_ret = dynamic_cast<Zi *>(p_fuv_zi);
	p_ret->fun();		   //zi fun ...
	p_ret->fuVirtualFun(); //zi fuVirtualFun ... 如果子类未重写父类方法的话，则调用父类方法

	printf("\n---------------4.不相干类之间转换-------------------------\n");
	//这个在平时开发中用不到吧。。
	A *pA = new A;
	B *pB = dynamic_cast<B *>(pA); //ok; 这也行。。A必须有虚函数
	pB->fun(); //b fun ...

	printf("\n---------------5.不能转换基本类型-------------------------\n");
	int i = 10;
	// double d = dynamic_cast<double>(i); //error; 不能用于基本类型的转换
	A a;
	// B b = dynamic_cast<B&>(a);
	return 0;
}
