/*
 * MainUnion.c
 *
 *  Created on: 2019年3月14日
 *      Author: BTI-PC
 *
 *	联合体
 *		1.联合体只能保存一个值，且以类型最大的一个为准；值为最后赋值的值
 *		2.联合体实例化有两种：
 *			1.直接在{}后面实例化
 *			2.union unionName name;
 *		3.联合体可内嵌结构体，但貌似不太好使，具体原因待确定。。
 *		4.联合体里的字符数组用strcpy()函数不好使。
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union Person
{
	char *name;
	int age;
	char favour[50]; //爱好
	// int age;
	struct
	{ //这个地方可以没有类型名
		int mathLevel;
		int englishLevel;
	} innerStruct;
} un_person;

void printPerson(union Person p)
{
	printf("printPerson --> p.age=%d\n", p.age);
}
int main()
{
	printf("-------------------1.使用定义时的实例-------------------\n");
	printf("size of un_person: %lu\n", sizeof(un_person));//56
	printf("un_person=%#x\n", un_person); //1
	printf("&un_person.name=%#x\n", &un_person.name); 
	printf("&un_person.age=%#x\n", &un_person.age); 
	printf("&un_person.favour=%#x\n", &un_person.favour); 
	un_person.name = "Lee";
	un_person.age = 13;
	un_person.favour[0] = 'y';
	
	// strcpy(un_person.favour, "basketball");//error
	un_person.innerStruct.mathLevel = 89; 

	// printf("un_person.name : %s\n", un_person.name);//error;联合体内容已经改变，访问了非法的地址
	printf("un_person.age : %d\n", un_person.age);
	printf("un_person.favour : %s\n", un_person.favour);
	printf("un_person.innerStruct.mathLevel : %d\n", un_person.innerStruct.mathLevel);

	printPerson(un_person);

	printf("\n-------------------2.新创建实例-------------------\n");

	//第二种实例化，跟C++不同，这里要在前面加关键字union
	union Person un_person2;
	un_person2.age = 14;
	printf("un_person2.age : %d\n", un_person2.age);

	printf("\n-------------------3.typedef-------------------\n");
	typedef union Person MyPerson;
	MyPerson p;
	p.age=17;
	printf("p.age = %d\n", p.age);

	return 0;
}

