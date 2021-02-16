/**
 * 	Created on: 2019年3月5日
 * 
 * 1.构造函数可以重载，析构函数不可以重载
 * 2.成员变量默认private修饰
 * 3.默认有两个构造函数:空构造函数和复制构造函数。
 * 4.如果写了有参构造，当需要需要无参构造实例化对象时，要写无参构造
 * 5.this:本对象object的地址，是个指针
 * 6.析构函数：
 * 		一个类仅有一个析构函数；
 * 		如果没有定义编译器默认生成；如果定义了，编译器不再生成；
 * 		在对象被释放时调用，可以在此时做一些释放内存的动作；
 * 7.类的大小取决于所有成员变量；
 *   c++在创建对象时仅分配用于保存成员变量的空间，而成员函数则分配到存储空的一个公共区域，由该类所有示例对象共享
 *   这一点和python类似,都是一个类对象持有函数,具体实例对象传参去调用即可
 *   参考：https://blog.csdn.net/weixin_36571185/article/details/89495281
 * 8.可以new带参构造,如new Person("Lee3", 3, "english")
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;

class Person
{
private: //不加private, public 等修饰符,默认是private
	string name;
	int age;
	
public:
	Person();					  //无参构造;要使用Person p 的方式实例化对象,必须要实现该构造
	Person(string name, int age); //有参构造
	~Person();					  //析构函数

public:
	void setName(string name) //可以在类内部实现
	{
		this->name = name;
	}
	void play();
	string toString(); //可以在类外部实现
};
// 无参构造;可以使用下述方式初始化属性
Person::Person() : 
	age(-1), 
	name("default_name")
{
	printf("无参构造被调用,this = %#x\n", this);
}
// 有参构造
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
	printf("有参构造被调用,this = %#x\n", this);
}
void Person::play(){
	printf("%s play\n",this->name.data());
}
string Person::toString()
{
	return "name="+name + ",age= " + std::to_string(age);
}
Person::~Person()
{
	printf("析构函数被调用 this = %#x\n", this);
}
int main()
{
	printf("---------------------1.无参构造----------------------------\n");
	Person p1; //在有有参构造的情况下，实例化无参构造的对象时需要实现无参构造
	printf("sizeof(p1): %d\n", sizeof(p1)); //40;类的大小取决于成员变量
	// p1.name = "lee1"; //error;属性默认是private修饰
	p1.setName("lee1");
	printf("p1: %s\n",p1.toString().data());

	printf("\n---------------------2.有参构造----------------------------\n");
	Person p2("lee2", 18);//引用类型
	printf("sizeof(p2): %d\n", sizeof(p2)); //40;类的大小取决于成员变量
	printf("p2 : %s\n", p2.toString().data());

	printf("\n---------------------3.对象指针----------------------------\n");
	Person *personP1, *personP2,*personP3,*personP4;
	personP1 = &p1;
	personP2 = &p2;
	personP3 = new Person; //申请动态内存，返回指针类型变量;会调用无参构造
						//	personP3 = new Person("Lee3", 3, "english");//ok;可以new带参构造
						//	personP3->Person("Lee3", 3, "english");//error;
	personP4 = new Person("lee34",18);
	cout << "personP1 : " << personP1 << endl;
	cout << "personP2 : " << personP2 << endl;
	cout << "personP3 : " << personP3 << endl;
	cout << "personP4 : " << personP4 << endl;

	personP1->play();
	personP2->play();
	personP3->play();
	personP4->play();

	delete personP3; //主动删除指针,析构函数才会被调用
	return 0;
}



