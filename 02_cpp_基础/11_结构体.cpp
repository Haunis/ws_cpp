/**
 *	结构体中可以存放函数指针:
 *		函数指针可以在定义里就初始化，或者在获取实例后再重新指向一个函数
 *		如果函数指针在定义时就初始化,不能Student stu={}这种方式实例化
 *
 *	实例化：
 *		方式一：结构体后面直接定义某个实例；如Student{...} student
 *		方式二：结构体名 实例化别名； 如 Student student
 *
 *	感觉c++使用typedef struct没什么意义,C语言里使用更方便点
 *	因为C语言定义结构体变量,前面要加struct关键字
 *	参考:https://www.cnblogs.com/ZY-Dream/p/10033991.html
 *
 *
 */
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void study(string str)
{
	printf("study-->%s\n",str.data());
}

void play(string str)
{
	printf("play --> %s\n", str.data());
}

struct Student
{
	char name[30];
	int age;
	// void (*p_func)(string)=study;//c++11 可以定义非静态函数;但是这样赋值后 Student stu={}实例化会失败
	void (*p_func)(string);
} student; //student是个实例化变量

typedef struct Person
{
	char name[30];
//	char *name;//如果使用指针就可以 p.name = "王五",直接赋值,因为常量指针可以指向其他地方
} MyPerson; //MyPerson是个结构体类型=struct Person


int main()
{
	printf("-------------------1.直接调用实例化好的结构体--------------------\n");
	strcpy(student.name, "lee1"); //给char[]赋值比较麻烦
	student.age = 27;
	printf("student.name=%s, student.age=%d\n", student.name, student.age);

	printf("\n-------------------2.1 结构体实例化1:Stuent stu--------------------\n");
	Student stu1; //实例化。不用像java里的初始化.c语言除非使用typedef否则必须加上struct关键字
	strcpy(stu1.name, "lee21"); //name像是指针常量，不能直接赋值。但可以对数组里的元素单个赋值
	stu1.age = 28;
	printf("stu1.name=%s, stu1.age=%d\n", stu1.name, stu1.age);

	printf("\n-------------------2.2 结构体实例化:Stuent stu = {}--------------------\n");
	Student stu2={"lee22",17,play},stu3; //结构体里的函数指针初始化时赋值后,不能这样实例化结构体
	printf("stu2.name=%s\n",stu2.name);
	stu2.p_func("basketball");

	strcpy(stu3.name,"lee23");
	printf("stu3.name=%s\n", stu3.name);
	

	printf("\n-------------------3.使用typedef的结构体---------------------\n");
	//和C语言不同,C语言要定义结构体变量要使用struct关键字,所以C语言使用typedef更何时
	
	MyPerson person;
	strcpy(person.name, "王五");
//	person.name="王五";//error; error.name相当于指针常量,不能指向其他地方
	printf("person.name=%s\n", person.name);

	return 0;
}

