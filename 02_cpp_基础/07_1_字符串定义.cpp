/*
 *  1.string：
 *  	string不是基本数据类型。要引入<string>头文件和std标准明明空间才可以使用
 *
 * 	2.char* arg
 * 	
 * 	3.char arg[]
 * 
 * 
 *	char* arg 和char arg1[]区别:
 *		char* arg = "hello":
 *			arg 指向字符串常量;
 *			常量指针; 可以指向别的地方, 如arg="abcd"可以指向新字符串 "abcd"
 *			以为指向的是字符常量,所以里面内容不可修改, 如*arg = 'a'会报错
 *		char arg1[]:
 *			arg1指向数组首地址;
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
	string ss = "hello"; // 32字节

	printf("ss=%s, sizeof(ss)=%lu\n", ss.data(), sizeof(ss)); //32

	printf("\n----------------------2.char*--------------------------\n");
	// char *char_p = "hello"; //size-8;ok,但是编译时会有warn，因为"hello"是个常量
	char const *char_p = "hello"; //size-8; //常量指针
	// char *char_p = (char*)"hello"; //size-8;
	printf("char_p=%s, sizeof(char_p)=%lu\n", char_p, sizeof(char_p)); //hello,8
	printf("*(char_p+0)=%c\n", *(char_p + 0));//h
	printf("*(char_p+1)=%c\n", *(char_p + 1));//e
	printf("*(char_p+2)=%c\n", *(char_p + 2));//l
	printf("*(char_p+3)=%c\n", *(char_p + 3));//l
	printf("*(char_p+4)=%c\n", *(char_p + 4));//o
	// char_p = "abcde";	//ok; 常量指针,可以指向其他地方
	// *char_p = 'e'; //编译ok,但运行error;常量指针里面内容不可修改
	printf("常量指针可以指向其他地方，修改后 char_p = %s\n",char_p);

	printf("\n----------------------3.char[]--------------------------\n");
	// char char_arr1[];//error;必须指定大小
	// char char_arr1[50];//ok
	char char_arr1[] = "hello";	// size-6; 
	
	// char char_arr2[6] = "helloo";//error; char_array会默认加上\0,只能存5个字符
	char char_arr2[6] = "hello"; //size-6;但最多只能放5个字符，最后一个位置放\0,表示结束

	// char char_arr3[6] = {'h', 'e', 'l', 'l','o','o'};//size-6;虽然编译和运行都能过，但是没有结束符，危险；开发时不能使用
	char char_arr3[6] = {'h', 'e', 'l', 'l','o'};//size-6
	printf("char_arr1=%s, sizeof(char_arr1)=%lu\n", char_arr1, sizeof(char_arr1)); //6
	printf("char_arr2=%s, sizeof(char_arr2)=%lu\n", char_arr2, sizeof(char_arr2)); //6
	printf("char_arr3=%s, sizeof(char_arr3)=%lu\n", char_arr3, sizeof(char_arr3)); //6

	printf("*(char_arr1+0)=%c\n", *(char_arr1 + 0)); //h
	printf("*(char_arr1+1)=%c\n", *(char_arr1 + 1)); //e
	printf("*(char_arr1+2)=%c\n", *(char_arr1 + 2)); //l
	printf("*(char_arr1+3)=%c\n", *(char_arr1 + 3)); //l
	printf("*(char_arr1+4)=%c\n", *(char_arr1 + 4)); //o

	//  char_arr1 = "abcd";//编译error;像是指针常量,指向数组首地址,不可指向其他地方
	*char_arr1 = 'x';//ok;像是指针常量,里面的内容可以修改
	printf("char_arr1=%s \n", char_arr1); //6
}
