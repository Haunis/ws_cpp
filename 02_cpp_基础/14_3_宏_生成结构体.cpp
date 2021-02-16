/*
 * 参考AndroidRuntime.cpp的写法;用宏生成一个结构体
 *
 * 当一个宏定义太长时,可以使用 "\"进行换行
 *
 */
#include <stdio.h>
#include <iostream>
using namespace std;

//#define REG_JNI(name) { name } //ok
#define REG_JNI(name) \
		{ name }

struct RegJNIRe
{
	int (*mProc)(int*); //函数指针;函数名-mProc,参数-int*,返回值-int
};
int fun(int *p)
{
	printf("fun called *p= %d\n", *p);
	return -1;
}

int main()
{
	int temp_a = 3;
	RegJNIRe reg = REG_JNI(fun); //用宏生成一个结构体
	reg.mProc(&temp_a);

	RegJNIRe gRegJNI[] = { REG_JNI(fun) };
	gRegJNI[0].mProc(&temp_a);

	return 0;
}
