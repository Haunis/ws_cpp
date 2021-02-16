/**
 *  strlen:要引入string.h
 *
 *	c++会在字符常量如"hello"加上'\0作为'结束, 但不会给字符数组如{}加上
 *
 *  strlen和sizeof区别:
 *  	strlen:可以获取char*和char[]定义的字符串长度,不算'\0'
 *  	sizeof:char*获取的是指针大小;
 *  		char[]指向字符串常量如"hello"则长度算上'\0',char[]指向数组如{'h','e'}则长度是数组实际长度
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	printf("\n----------------1.数组不带{}----------------\n");
	char str1[] = "hello"; //会给字符常量加上结束符
//	char str1[5] = "hello";//error
//	char str1[6] = "hello";//ok
	printf("str1=%s,strlen(str1)=%d\n", str1, strlen(str1)); //5
	printf("str1=%s,sizeof(str1)=%d\n", str1, sizeof(str1)); //6

	printf("\n----------------2.字符指针指向常量----------------\n");
	char *str2 = "hello";//实际上是const char *
	printf("str2=%s,strlen(str2)=%d\n", str2, strlen(str2)); //5
	printf("str2=%s,sizeof(str2)=%d\n", str2, sizeof(str2)); //8;指针大小

	printf("\n----------------3.数组带\\0----------------\n"); //将\0转义
	char str3[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	printf("str3=%s,strlen(str3)=%d\n", str3, strlen(str3)); //5
	printf("str3=%s,sizeof(str3)=%d\n", str3, sizeof(str3)); //6

	printf("\n----------------4.数组不带\\0----------------\n");
	char str4[5] = { 'h', 'e', 'l', 'l', 'o' };
	printf("str4=%s,strlen(str4)=%d\n", str4, strlen(str4)); //10? 没有结束符....
	printf("str4=%s,sizeof(str4)=%d\n", str4, sizeof(str4)); //5

	return 0;
}
