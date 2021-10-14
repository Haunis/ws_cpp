/**
 * 	参考：https://blog.csdn.net/m0_37806112/article/details/82467683
 *
 * 	主要演示类的成员变量可以初始化哪些类型的变量
 * 
 *	类的成员变量可以初始化：
 *		基本类型，数组,string，无参构造的对象
 *		必须要初始化静态常量const static int MY_COUNT = 111
 *
 *	不可以初始化:
 *		1.带参对象
 *		2.不可以初始化静态成员，静态成员必须在类的外部定义或者初始化后方可使用
 *		  静态成员必须在类的外部定义(int Person::static_count)或者初始化后(int Person::count2 = 2)方可使用
 *
 *	可以new带参构造的对象，如new Student("lee2", 27)
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Student //辅助类
{
public:
	string name;
	int age;

public:
	Student() : age(20), name("lee") //初始化 age,name
	{
		printf("Student 无参构造调用 %#x\n", this);
	};
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
		printf("Student 有构造调用\n");
	}
	string toString()
	{
		return "name=" + name + ",age=" + std::to_string(age);
	}
};

class Person //使用这个类进行初始化验证
{
public:
	int age = 18;					 //可以初始化基本类型
	string name = "default_name";	 //可以初始化string
	const static int MY_COUNT = 100; //常量，必须要初始化

	Student stu;	//ok;可以初始化无参构造对象；会调用默认构造创建对象
	Student *stu_p = nullptr; //ok;不会调用构造,不会创建对象; 注意要初始化为nullptr
	// Student stu2("Twang", 18); //error;类内的对象不能显式调用非默认构造函数

	// static int static_count = 100;//error; 不能为静态成员初始化,必须在类的外部定义或者初始化后方可使用
	static int static_count; //可以声明;

	int favour[4] = {1, 2, 3}; //ok;可以初始化数组
public:
	Person() //实例化时必须要有该无参构造
	{
		printf("person 无参构造 调用\n");
	}
	Person(Student Student)
	{
		printf("person 有参构造 studen\n");
		this->stu = Student;
	}
	Person(string name, int age)
	{
		printf("person 有参构造 name=%s,age=%d\n", name.data(), age);
		this->name = name;
		this->age = age;
	}
	Person(Student *p)
	{
		printf("person 参数为指针构造 ，p=%#x\n", p);
	}

	string toString()
	{
		return name + " , " + to_string(age) + ", stu[ " + stu.toString() + "]";
	}
};
// int Person::static_count; //必须在类外定义
int Person::static_count = 100; //在类外定义并初始化

int main()
{
	printf("\n----------------1.1 默认使用无参构造实例化对象-----------------\n");
	Person p1;
	printf("p1 : %s\n", p1.toString().data());
	printf("static_count = %d\n", Person::static_count);

	cout << "favour[0]:" << p1.favour[0] << endl;
	cout << "favour[1]:" << p1.favour[1] << endl;
	cout << "favour[2]:" << p1.favour[2] << endl;
	printf("\n----------------1.2 使用无参构造实例化对象-----------------\n");
	Person p2("lee2", 18);
	printf("p2 : %s\n", p2.toString().data());

	printf("\n----------------2.new-----------------\n");
	// Person *pPeson = new Person;//ok; 使用默认的构造
	Person *pPerson = new Person("lee2", 17);
	cout << "toString: " << pPerson->toString().data() << endl;
	cout<<"stu_p : "<<pPerson->stu_p<<endl; //有可能不为0
	delete pPerson;

	printf("\n----------------3.构造参数为指针-----------------\n");
	// Person p(new Student);	//ok
	Person p = new Student; //这种写法也行，实际调用的是Person构造函数

	return 0;
}
