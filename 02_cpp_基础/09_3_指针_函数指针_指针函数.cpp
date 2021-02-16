/**
 *
 * 函数型指针：
 * 		指向函数
 * 		最大的作用是把函数作为一个参数传递给另外一个函数
 * 		函数指针定义:int (*sub)(int, int);
 * 		函数指针赋值:sub=subtraction;
 *
 * int (*sub)(int, int)=subtraction;
 *		sub就代表了subtraction,()里的两个int只是变量类型的声明，是一种形参而不是实参

 * 指针函数：
 * 		函数返回类型为指针，如： void* test(){return pointer;}
 *
 *函数指针和指针函数：
	https://blog.csdn.net/paoxungan5156/article/details/106783001
	https://blog.csdn.net/lyn_00/article/details/83549655#commentBox
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int subtraction(int a, int b)
{
	return a - b;
}
int addition(int a, int b)
{
	return a + b;
}

int operation(int x, int y, int (*func)(int, int))
{
	printf("operation,func=%#x\n", (unsigned int)(long)func);
	//	int result = (*func)(x, y);//貌似两种调用皆可
	int result = func(x, y);
	return result;
}

/*	
	func是一个函数,返回一个函数指针int (*p)(int,int);
	逐步拆解分析：
	1.func(int x, int (*f)(int,int))
		表示func是个函数，该函数参数有两个：int x和一个函数指针f
	2.*func(int x, int (*f)(int,int))
		表示func是个指针函数,返回一个函数指针
	3.int (*func(int x, int (*f)(int,int)))(int a,int b)
		指针函数func返回的函数指针，指向一个函数，这个函数参数有两个：a和b.且该函数返回值是int类型

	简单地写就是: int( *func())(); func返回一个函数指针，该指针指向的函数无参数，返回值为int

	实现了某些功能，更是返回函数指针，这个可以实现闭包？？？
*/
int (*func(int x, int (*f)(int, int)))(int a, int b)
{
	printf("func called x=%d\n", x);
	// return addition;//ok; 只要是 int temp(int,int)这样的函数都行
	return f;
}

/**
 * 上面的这种int (*func(int x, int (*f)(int, int)))(int a, int b)写法太复杂
 * 可使用typedef，将函数指针"变量"func_p声明成一个函数指针"类型"
 */
typedef int (*func_p)(int, int);
func_p test()//函数返回函数指针类型
{
	printf("test called \n");
	return addition;
}

int main(int arg, char *argv[])
{

	printf("\n----------------1.函数指针-------------------\n");
	int (*sub)(int, int) = subtraction;
	int (*add)(int, int) = addition;
	int subResult = operation(4, 2, sub);
	int addResult = operation(4, 2, add);
	cout << "subResult=" << subResult << endl;
	cout << "addResult=" << addResult << endl;

	printf("\n----------------2.指针函数返回函数指针-------------------\n");

	//func返回函数指针，用这个函数指针再调用函数
	int ret = func(100, addition)(3, 4);
	printf("ret=%d\n", ret);

	int (*f)(int, int) = func(200, subtraction);
	ret = f(3, 4);
	printf("ret=%d\n", ret);

	printf("\n----------------3.typedef声明函数指针-------------------\n");
	ret = test()(3, 4);//test()返回函数指针，函数指针调用函数
	printf("ret=%d\n", ret);

	return 0;
}
