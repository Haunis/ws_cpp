/**
 * 使用Linux Gcc要引入stdlib.h头文件
 * 1.int* p =new int [4] ；new 与普通数组区别： 普通数组长度固定，指针是个常量。
 *	    使用完记得用delete释放。内存可能会被用完，所以申请之后要校验指针是否为空，if(p==NULL)
 * 2.malloc与calloc区别： 语法区别calloc函数有两个参数
 *
 * new和delete不是函数,是c++里的关键字
 * new申请内存之后可以初始化,如 string *s = new string("hello");
 * malloc申请之后不会
 *
 *
 */
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void printArray(void *p, int eleType, int arrayLength);
void newFun();
void mallocFun();
void callocFun();
void reallocFun();
int main()
{
	printf("------------------1.newFun------------------\n");
	newFun();

	printf("\n----------------2.mallocFun------------------\n");
	mallocFun();

	printf("\n----------------3.callocFun------------------\n");
	callocFun();

	printf("\n----------------4.reallocFun------------------\n");
	reallocFun();

	return 0;
}
void newFun()
{
	int length = 4;
	int *p = new int[length]; //指针数组，数组里存放的是指针
	*(p + 0) = 10;
	*(p + 1) = 11;
	*(p + 2) = 12;
	*(p + 3) = 13;
	printArray(p, sizeof(int), length);

	printf("before delete p=%#x\n", p);
	delete p; //释放内存
	printf("after delete p=%#x\n", p);
	printArray(p, sizeof(int), length);

	string *s = new string("hello"); //new申请动态内存之后可以初始化
	printf("s = %s\n", s->data());
}
void reallocFun()
{
	int length = 4;
	int *p = (int*) calloc(length, sizeof(int)); //第一个参数是元素个数，第二个参数是每个元素的长度。默认返回void*,要强转
	*(p + 0) = 10;
	*(p + 1) = 11;
	*(p + 2) = 12;
	*(p + 3) = 13;
	printArray(p, sizeof(int), length);

	cout << "rellocFun after" << endl;
	int appendLength = 3;
	int *newP = (int*) realloc(p, (length + appendLength) * sizeof(int));
	*(newP + length + 0) = 44;
	*(newP + length + 1) = 55;
	*(newP + length + 2) = 66;
	printArray(newP, sizeof(int), length + appendLength);

	free(newP);
	cout << "free----" << endl;
	printArray(newP, sizeof(int), length + appendLength);
}
void callocFun()
{
	int length = 4;
	int *p = (int*) calloc(length, sizeof(int)); //第一个参数是元素个数，第二个参数是每个元素的长度。默认返回void*,要强转
	*(p + 0) = 10;
	*(p + 1) = 11;
	*(p + 2) = 12;
	*(p + 3) = 13;
	printArray(p, sizeof(int), length);

	free(p);
	cout << "free----" << endl;
	printArray(p, sizeof(int), length);
}
void mallocFun()
{
	int length = 4;
	int *p = (int*) malloc(length * sizeof(int)); //默认返回void*类型指针，所以要强转
	*(p + 0) = 0;
	*(p + 1) = 1;
	*(p + 2) = 2;
	*(p + 3) = 3;
	printArray(p, sizeof(int), length);

	free(p);
	cout << "free----" << endl;
	printArray(p, sizeof(int), length);
}

void printArray(void *p, int eleType, int arrayLength)
{
	switch (eleType)
	{
	case sizeof(int):
		int *intP = (int*) p;
		for (int i = 0; i < arrayLength; i++)
		{
			cout << "*(intP+" << i << ") =" << *(intP + i) << endl;
		}
		break;
	}
}
