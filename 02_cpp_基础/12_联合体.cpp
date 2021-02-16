/*
 * MainMyDef.cpp
 *
 *  Created on: 2019年3月5日
 *
 *	联合体
 *		所有被声明的元素占同一段内存空间，其大小取决于声明中最长的元素的大小。
 *		改变其中一个 元素的值将会影响所有其他元素的值。或者说，只能保存一个值，值为最后赋的值。
 *
 *	匿名联合
 *		如果结构体中的联合体没有名字，就称为匿名联合体，用法：struct.联合体中的属性
 *
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

union Person
{
	char name[50];
	int age;
	struct //这个地方可以没有类型名
	{
		int mathLevel;
		int englishLevel;
	} struct_in; //struct_in是个变量
} un_person;	 //un_person是个变量

//------------------匿名联合体----------------//
struct Animal
{
	bool fly;
	char type[50];
	union //可以没有类型名
	{
		char inner_name[50];
		int inner_age;
	};
	//联合体没有名字就是匿名联合体
};

int main()
{
	printf("-------------------1.1 使用定义时的实例-------------------\n");
	printf("size of un_person: %lu\n", sizeof(un_person)); //52
	printf("sizeof(un_person.name)=%d\n", sizeof(un_person.name)); //50
	printf("sizeof(un_person.age)=%d\n", sizeof(un_person.age)); //4

	printf("un_person=%#x\n", un_person);//1
	printf("&un_person.name=%#x\n", &un_person.name);
	printf("&un_person.age=%#x\n", &un_person.age);

	un_person.struct_in.englishLevel = 88; //直接使用联合体变量
	printf("un_person.struct_in.englishLevel=%d\n", un_person.struct_in.englishLevel);
	
	printf("\n-------------------1.2 新创建实例-------------------\n");
	//实例化。 C语言里实例化要加union关键字在前面,c++不需要
	Person p;
	strcpy(p.name, "李三"); //将"李三"copy到un2.name
	printf("p.name=%s\n", p.name);
	printf("sizeof(p)=%d\n", sizeof(p)); //52

	printf("\n------------------2.匿名联合体-----------------------\n");
	Animal animal;//直接实例化一个结构体
	Animal *p_animal = &animal;

	p_animal->fly = true;
	cout << "p_animal->fly = " << p_animal->fly << endl;
	
	p_animal->inner_age = 9; //直接使用匿名联合体中的属性，不用再 [struct.union.属性];
	cout << "p_animal->age = " << p_animal->inner_age << endl;

	return 0;
}
