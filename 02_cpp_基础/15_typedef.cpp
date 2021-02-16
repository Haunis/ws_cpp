/**
 * https://www.cnblogs.com/shijingjing07/p/5591896.html
 * 
 * 定义一种类型的别名
 * 
 * 格式： typedef int myint;//定义后myint与int一样使用
 */
#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

//定义int别名
typedef int myint;

//定义结构题别名
typedef struct Person
{
	char name[30];
} MyPerson; //MyPerson是个结构体类型=struct Person

//定义函数指针别名
typedef int (*func_p)(int, int);
func_p fun_test(int (*func)(int, int))
{
	return func;
}
int sum(int x, int y) { return x + y; }

int main()
{
	printf("---------------1.定义int别名--------------\n");
	myint i = 3;
	printf("i = %d\n", i);

	printf("\n-------------2.定义结构体别名--------------\n");
	printf("typeid(Person).name()=%s\n", typeid(Person).name());	 //6Person
	printf("typeid(MyPerson).name()=%s\n", typeid(MyPerson).name()); //6Person

	printf("\n-------------3.定义函数指针--------------\n");
	// func_p func = sum;//ok
	func_p func = fun_test(sum);
	int ret = func(2, 3);
	printf("ret = %d\n", ret);
	return 0;
}
