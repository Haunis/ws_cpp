/*
 *  Created on: 2019年2月28日
 *  Author: BTI-PC
 *
 *	数组变量像是指针常量，存储的地址不变，不能指向其他地方，但是指向的内存区域的值可以变
 *  char char_arr[] ="hello"; char_arr是指针常量
 *	char* char_p = "hello";char_p是常量指针，指向的区域hello内容不可修改，但是指针可以指向其他地方
 *
 *	数组名对应着（而不是指向）一块内存，其地址与容量在生命期内保持不变，只有数组的内容可以改变。
 *	注意当数组作为函数的参数进行传递时，该数组自动退化为同类型的指针。

 *	可以将数组赋值给一个指针
 *  如： int arr1[] = {1, 2, 3}; 
 * 		int *arr_p1 = arr1; 
 * 但不允许这样使用： int *arr_p = {1,2,3}; 
 * 
 *	https://zhidao.baidu.com/question/166983415.html
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>

#define WIDTH 4
#define HEIGHT 5
using namespace std;

void printArray(int array[], int length);

int main()
{
	printf("--------------------1.方式1初始化------------------------\n");
	int arr1[] = {1, 2, 3}; //变量arr1对应第一个元素的地址，不是指向

	printf("arr1: %#x\n", (unsigned int)(long)arr1);
	printf("&arr1:%#x\n", (unsigned int)(long)&arr1);
	printf("&arr1[0]:%#x\n", (unsigned int)(long)&arr1[0]); //这三个地址相等

	printf("sizeof(arr1) = %lu\n", sizeof(arr1)); //12; 3个int,一个int占4个字节，所以共3*4=12 byte

	printArray(arr1, sizeof(arr1) / sizeof(int));

	printf("\n可以将数组赋给一个指针\n");
	// int *arr_p1 = {1, 2, 3};//error;虽然数组变量像是指针，但是也不能这样写
	int *arr_p1 = arr1;		//ok；arr_p1是指针变量，初始值等于arr
	int *arr_p2 = &arr1[0]; //ok

	*(arr_p1 + 0) = 100;
	printf("arr1[0]:%d\n", arr1[0]); //arr_p1指向的区域和arr1对应的区域是同一块区域，所以arr1[0]值会变

	printf("\n--------------------2.方式2初始化------------------------\n");
	int arr2[5] = {1, 2, 3, 4, 5};
	arr2[0] = arr2[0] * 10;//赋值方式1
	*(arr2 + 1) = *(arr2 + 1) * 10; //赋值方式2这两种赋值方式都行
	printArray(arr2, 5);

	printf("\n--------------------3.方式3初始化------------------------\n");
	int arr3[5]; //数组中每个元素初始化为0
}

//当数组作为函数的参数进行传递时，该数组自动退化为同类型的指针。
void printArray(int array[], int length)
{
	printf("-->sizeof(array)=%lu\n", sizeof(array));	   //8
	printf("-->&array=%#x\n", (unsigned int)(long)&array); //array是个新的指针变量，指向数组首地址
	printf("-->array=%#x\n", (unsigned int)(long)array);

	printf("-->");
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", *(array + i));
	}
	printf("\n");
}
