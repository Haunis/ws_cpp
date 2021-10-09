/*
 *  Created on: 2019年3月6日
 *	https://blog.csdn.net/m0_37806112/article/details/82467683
 *		
* 	static有两种用法：面向过程的static和面向对象的static,本demo是面向对象的static
 * 		https://blog.csdn.net/legend_hua/article/details/78193239
 * 
 * const静态类成员可以直接初始化，其他非const的静态类成员需要在类外全局作用域下初始化，且不能使用static关键字
 * https://blog.csdn.net/qq_43915356/article/details/107368218
 * 
 * 静态成员是“类级别”的，也就是它和类的地位等同，而普通成员是“对象（实例）级别”的。    
 * 类级别的成员，先于该类任何对象的存在而存在，它被该类所有的对象共享
 * 
 *	静态成员变量:
 *		定义：static int staticCount；
			注意不能在类的内部为静态成员变量初始化
			静态成员必须在类的外部定义(int Student::staticCount)或者初始化后(int Student::staticCount = 222)方可使用
 *      调用：Class::staticCount；
 * 
 * 	静态函数：
 * 		定义：void static staticFun();
 * 		调用：Class::staticFun();
 *
 */
#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;
// class Student;
// int Student::staticCount = 0; //error,不能在类声明静态成员前使用静态成员

class Student
{
public:
	int x, y, z, aa;
	static int staticCount; //静态变量，也称类变量；不依赖具体的对象，和java里静态一个意思;不能为静态成员初始化
	const static int TEMP_STATIC = 100;//const修饰的是ok的

public:
	Student();	//构造函数，函数体在别的地方实现
	~Student(); //析构函数，object被释放时调用
public:
	void static staticFun(); //静态函数
};
void Student::staticFun()
{
	printf("staticFun invoked\n");
}
Student::Student()
{
	staticCount++;
}

Student::~Student()
{
	staticCount--;
}
// int Student::staticCount; //ok;定义
// int Student::staticCount = 10; //初始化
int Student::staticCount(10); //这样也是可以初始化

int main()
{
	printf("----------------1.调用静态成员变量----------------------\n");
	cout << "staticCount : " << Student::staticCount << endl;
	cout << "TEMP_STATIC : " << Student::TEMP_STATIC << endl;

	printf("\n--------------2.调用静态函数----------------------\n");
	Student::staticFun(); //调用静态函数


	return 0;
}
