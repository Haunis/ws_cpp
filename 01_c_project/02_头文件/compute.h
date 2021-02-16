#ifndef COMPUTE_H_
#define COMPUTE_H_

#include<stdio.h>
#include<stdlib.h>

int add(int x, int y);
int multi(int x, int y);

//int i; //声明也是定义，未初始化; 如果引用此头文件的文件在全局定义了如 i= 8会有链接错误
//int i = 8; //声明且定义，当有多个文件引用此头文件时，会有链接错误

extern int i; //只声明不定义;如果引用此头文件的文件在全局定义了如 i= 8会有链接错误
//extern int i = 3;//被当做 int i = 3; 声明且定义;

static void test_fun() //不用static修饰的话就会报重复定义的错误
{
	printf("test_fun called \n");
}

#endif /* COMPUTE_H_ */
