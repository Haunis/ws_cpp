/*
 *  1.string：
 *  	string不是基本数据类型。要引入<string>头文件和std标准明明空间才可以使用
 * 		string ss = "hello";						//size-32
 *
 * 	2.char* arg
 *		char *cp = "hello"; 						// size-8, strlen-5

 * 	3.char arg[]
 * 		char arr1[] = "hello"; 						// size-6, strlen-5; 推荐使用；默认在后面填充'\0'; 像指针常量，不能指向其他地址
 *		char arr2[6] = {'h', 'e', 'l', 'l', 'o'};   // size-6, strlen-5; 像指针常量，不能指向其他地址
 * 		char arr1[] = {'h', 'e', 'l', 'l','o'}; 	// size-5, strlen-5; 虽然编译和运行都能过，但是没有结束符，危险；开发时不能使用
 * 		
 *
 *
 *	char* arg 和char arg1[]区别:
 *		char* arg = "hello":
 *			arg 指向字符串常量; 内容不可修改，但可指向其他地方
 *			常量指针; 可以指向别的地方, 如arg="abcd"可以指向新字符串 "abcd"
 *			以为指向的是字符常量,所以里面内容不可修改, 如*arg = 'a'会报错
 *		char arg1[]:
 *			arg1指向数组首地址; 内容可修改，但不可指向其他地方
 *			像指针常量,存储的地址不变；不能指向其他地方,如arg="abcd"会报错
 *			里面内容可以修改,arg1[0]='a'是ok的
 *
 */

#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
	printf("\n----------------------1.string--------------------------\n");
	string ss = "hello"; // size: 32 bytes

	printf("ss=%s, sizeof(ss)=%lu\n", ss.data(), sizeof(ss)); // 32

	printf("\n----------------------2.char*--------------------------\n");
	// char *cp = "hello"; //ok; size-8;编译时会有warn，因为"hello"是个常量
	// char *cp = (char*)"hello"; //ok;
	char const *cp = "hello"; // size-8; 常量指针

	printf("cp=%s, size=%ld, strlen=%ld\n", cp, sizeof(cp), strlen(cp)); // hello, 8, 5
	printf("*(cp+0)=%c\n", *(cp + 0));									 // h
	printf("*(cp+1)=%c\n", *(cp + 1));									 // e
	printf("*(cp+2)=%c\n", *(cp + 2));									 // l
	printf("*(cp+3)=%c\n", *(cp + 3));									 // l
	printf("*(cp+4)=%c\n", *(cp + 4));									 // o
	// printf("*(cp+5)=%c\n", *(cp + 5));// 结果不可预测...
	// printf("*(cp+6)=%c\n", *(cp + 6));// 指针访问越界，结果不可预测。。

	cp = "abcde"; // ok; 常量指针,可以指向其他地方
	// *cp = 'e'; //编译ok,但运行error;常量指针里面内容不可修改
	printf("常量指针可以指向其他地方，修改后 cp = %s\n", cp);

	printf("\n----------------------3.char[]--------------------------\n");
	// char arr1[];//error; 编译报错，必须指定大小
	char arr1[] = "hello"; // size-6,strlen-5; 默认在后面填充 '\0'; 像指针常量，不能指向其他地址

	printf("arr1=%s, size=%ld, strlen=%ld\n", arr1, sizeof(arr1), strlen(arr1)); // hello, 6, 5

	printf("*(arr1+0)=%c\n", *(arr1 + 0)); // h
	printf("*(arr1+1)=%c\n", *(arr1 + 1)); // e
	printf("*(arr1+2)=%c\n", *(arr1 + 2)); // l
	printf("*(arr1+3)=%c\n", *(arr1 + 3)); // l
	printf("*(arr1+4)=%c\n", *(arr1 + 4)); // o

	printf("arr1[0]=%c\n", arr1[0]); // h
	printf("arr1[1]=%c\n", arr1[1]); // e
	printf("arr1[2]=%c\n", arr1[2]); // l
	printf("arr1[3]=%c\n", arr1[3]); // l
	printf("arr1[4]=%c\n", arr1[4]); // o

	//  arr1 = "abcd";//编译error; 像是指针常量,指向数组首地址,不可指向其他地方
	*(arr1 + 0) = 'a';							   // ok;像是指针常量,里面的内容可以修改
	printf("内容可修改， 修改后arr1=%s \n", arr1); // aello

	printf("\n----------------------4.char[6]--------------------------\n");
	{
		printf("\n空数组...");
		char arr2[6]; // ok
		// arr2 = "hello"; //error; 像是指针常量,指向数组首地址,不可指向其他地方
		arr2[0]='x';
		printf("arr2=%s, size=%ld, strlen=%ld\n", arr2, sizeof(arr2), strlen(arr2)); // hello, 6, 5
	}

	{
		printf("\n指向字符常量...");
		// char arr2[6] = "hellox"; // error; 编译报错，只能存5个字符，最后会默认加上\0
		char arr2[6] = "hello";	// size-6; 但最多只能放5个字符，最后一个位置放\0,表示结束
		printf("arr2=%s, size=%ld, strlen=%ld\n", arr2, sizeof(arr2), strlen(arr2)); // hello, 6, 5
	}

	{
		printf("\n指向字符数组...");
		// char arr2[5] = {'h', 'e', 'l', 'l','o'};//size-5;虽然编译和运行都能过，但是没有结束符，危险；开发时不能使用
		// char arr2[] = {'h', 'e', 'l', 'l','o'};//size-5;虽然编译和运行都能过，但是没有结束符，危险；开发时不能使用
		char arr2[6] = {'h', 'e', 'l', 'l', 'o'}; // size-6
		printf("arr2=%s, size=%ld, strlen=%ld\n", arr2, sizeof(arr2), strlen(arr2)); // hello, 6, 5
	}
}
