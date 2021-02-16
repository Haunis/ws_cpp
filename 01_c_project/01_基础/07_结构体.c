/*
 *
 *  Created on: 2019年3月14日
 *  Author: BTI-PC
 *
 *	结构体
 *		1.实例化：
 *			C语言要定义一个结构体变量必须使用struct关键字,而c++不需要,所以C语言使用typedef更合适
 *			方式一: struct StructName structName; //和c++一样,先定义再赋值
 *			方式二: struct StructName structName = {}; //直接给变量初始化赋值
 *
 *		2.函数型指针变量赋值不可像C++一样直接在结构体内部赋值。可以实例化后赋值
 *			structName.funP = fun();
 *		3.间接引用运算符，访问指针所指向的结构体属性。左边必须是一级指针
 *
 *	结构体变量前加点:
 *		赋值时可以乱序,但c++不支持这种语法,c++必须保证顺序一致
 *		c可以乱序: https://bbs.csdn.net/topics/380157282
 *		c++不可乱序: https://blog.csdn.net/zuicong5568/article/details/77944474
 */

#include <stdio.h>
#include <stdlib.h>

void study(char *book)
{
	printf("study : %s\n", book);
}

int sum(int i, int j)
{
	return i + j;
}
struct Student
{
	char *name;
	int age;
	char sex;

	// void (*p_study)() = study; //error;C不允许这样直接给函数指针赋值
	void (*p_study)();
} student;
typedef struct
{
	char *name;
} Person;

int main()
{
	printf("-------------1.使用初始实例化的结构体--------------------\n");
	student.name = "lee0";
	printf("student.name=%s\n",student.name);

	printf("\n-------------2.1实例化方式1:struct Student stu1--------------------\n");
	//定义一个结构体变量后,再赋值
	struct Student stu1; //必须要有struct关键字,C++不需要
	stu1.name = "Lee1";	 //stu1.name 是个普通char*指针，所以可以指向其他地方
	stu1.age = 17;
	stu1.sex = 'm';
	stu1.p_study = study;

	printf("sizeof(stu1.name)=%lu\n", sizeof(stu1.name));		//8
	printf("sizeof(stu1.age)=%lu\n", sizeof(stu1.age));			//4
	printf("sizeof(stu1.sex)=%lu\n", sizeof(stu1.sex));			//1
	printf("sizeof(stu1.p_study)=%lu\n", sizeof(stu1.p_study)); //8
	printf("sizeof(stu1)=%lu\n", sizeof(stu1));					//24,为何多3个字节。。。

	printf("stu1.age : %d\n", stu1.age);
	printf("stu1.name : %s\n", stu1.name);
	stu1.p_study("Math");

	printf("\n-------------2.2实例化方式2:struct Student stu1={}------------------\n");
	struct Student stu2 = {"Lee2", 17, 'f', study};

	printf("stu2.age : %d\n", stu2.age);
	printf("stu2.name : %s\n", stu2.name);

	struct Student *stup = &stu2;
	stup->p_study("stup study English"); //间接引用运算符，访问指针所指向的结构体属性。左边必须是一级指针

	printf("\n-------------3.使用typedef----------------------\n");
	Person p;		 //使用了typedef后可以不使用struct关键字
	p.name = "张三"; //p.name是指针,所以可以指向其他地方
	printf("p.name=%s\n", p.name);

	printf("\n-------------4.结构体变量前加点-----------------------\n");
	//加.可以改变初始化顺序
	struct Student stu3 = {.age = 17, .sex = 'm', .name = "Lee3", .p_study = study};

	printf("name=%s\n", stu3.name);
	return 0;
}
