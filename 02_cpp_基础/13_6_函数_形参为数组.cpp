/*
 *  Created on: Apr 10, 2020
 *  Author: haunis
 *
 *  参考：https://www.runoob.com/cplusplus/cpp-passing-arrays-to-functions.html
 *
 *  c++中传递数组给函数，数组类型自动转换为指针类型，因而实际传递的是地址
 */
#include <stdio.h>
#include <iostream>
using namespace std;

//1.参数是一维数组;传过来的数组变量自动转换为指针类型
//arr是个指针，指向一块连续的内存区域--数组
void fun_arr(int arr[], int length) //_Z7fun_arrPii:
{
	printf("fun_arr --> &arr=%x\n", &arr);
	printf("fun_arr --> arr=%x\n", arr);
	printf("fun_arr --> &arr[0]=%x\n", &arr[0]);
	for (int i = 0; i < length; i++)
	{
		// arr[i] = arr[i] * 10; //ok
		*(arr + i) = *(arr + i) * 10; //这两种方式都行
	}
}
//2.参数值指针；
//p是个新指针,存储的是数组第一个元素的地址，存储的地址和本身的地址不相等
void fun_p(int *p, int length) //_Z5fun_pPi:
{
	printf("fun_p --> &p=%x\n", &p);
	printf("fun_p --> p=%x\n", p);
	printf("fun_p --> &p[0]=%x\n", &p[0]);
	for (int i = 0; i < length; i++)
	{
		// arr[i] = arr[i] * 10; //ok
		*(p + i) = *(p + i) * 10; 
	}
}

//3.参数是二维数组；必须要指定列数，这里是5列
//arr相当于行指针
// void fun_arr2(int arr[2][5],int row)
// void fun_arr2(int arr[][5],int row)
void fun_arr2(int (*arr)[5], int row) //ok; _Z8fun_arr2PA5_i:
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// arr[i][j] = arr[i][j] * 10;//ok
			*(*(arr + i) + j) = *(*(arr + i) + j) * 10;
		}
	}
}

//4.参数是二级指针
void fun_pp(int **pp)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pp[i][j] = pp[i][j] * 10;//
			// *(*(pp + i) + j) = *(*(pp + i) + j) * 10;
		}
	}
}

//打印一维数组
void print_arr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
//打印二维维数组
void print_arr2(int (*arr)[5], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}
//打印指针数组
void print_pp(int **pp)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", pp[i][j]);
			// printf("%d\t", *(*(pp + i) + j));
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) //第二个参数指针数组
{
	int arr_len = 5;
	int arr[arr_len] = {1, 2, 3, 4, 5}; //arr类似指针常量，不能指向其他地方；对应一块内存区域
	printf("&arr=%#x\n", &arr);
	printf("arr=%#x\n", arr);		  // arr这个变量很特殊。。后面有时间再深究
	printf("&arr[0]=%#x\n", &arr[0]); //这三个地址相等，就是首元素地址

	print_arr(arr, arr_len);

	printf("-----------------1.函数参数是数组----------------------\n");
	fun_arr(arr, arr_len); //c++中传递数组给函数,数组类型自动转换为指针类型，因而实际传递的是地址
	print_arr(arr, arr_len);

	printf("\n---------------2.函数参数是指针----------------------\n");
	fun_p(arr, arr_len);
	print_arr(arr, arr_len);

	printf("\n---------------3.函数参数是二维数组----------------------\n");
	//arr_2相当于行指针 int(*)[5],每行5个元素,行指针一次移动4*5byte,本质上还是一级指针
	int arr_2[2][5] = {{1, 2, 3, 4, 5},
					   {6, 7, 8, 9, 10}};
	print_arr2(arr_2, 2);
	fun_arr2(arr_2, 2);
	print_arr2(arr_2, 2);

	printf("\n---------------4.函数参数是二级指针----------------------\n");
	int a = 3, b = 4;
	int *p_arr[2] = {(int *)(arr_2 + 0), (int *)(arr_2 + 1)}; //p_arr是个指针数组,数组里存放两个指针
	fun_pp(p_arr);

	print_pp(p_arr);
	return 0;
}
