/*
 * MainFunction.c
 *
 *  Created on: 2019年3月14日
 *      Author: BTI-PC   
 *
 *	C里函数的使用和C++类似：main函数前面声明，main函数后面具体实现
 *	也可以像C++一样，可以将函数指针指向一个函数
 *
 *	原则上是先声明函数才可以使用，但是gcc可以编译不声明就直接使用的函数；
 *	但是g++编译不过
 *
 */

#include <stdio.h>
#include <stdlib.h>

void printFun(char *str);
void (*fun)(char *) = printFun; //参数 char* 可以不要

int main()
{
	fun("hello function");
	return 0;
}

void printFun(char *str)
{
	printf("printFun ---> %s\n", str);
}
