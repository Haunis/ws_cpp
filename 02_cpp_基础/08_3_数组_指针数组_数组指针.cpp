/*
 *数组指针：
 *	int(*arr_p)[3] = new int[10][3];
 *	[]的优先级更高，加上()后，就代表arr_p指向int[3]类型指针；arr_p+1跨过3*4个字节，也称行指针
 *
 * 指针数组：
 * 	数组里存放的是指针
 * 	int *p[3] = {&a, &b, &c};// p是个二级指针 ;int *结合,表示p指向int指针
 * 	int **pp = new int *[HEIGHT];
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>

#define WIDTH 4
#define HEIGHT 5
using namespace std;

int main()
{

	printf("\n--------------------1.1指针数组:存放int地址-----------------------\n");
	//数组里存放的是指针
	int a = 1, b = 2, c = 3;
	int *p_arr[3] = {&a, &b, &c}; //p_arr是二级指针;注意*p没加括号，加括号就是数组指针也就是行指针
	printf("p_arr+0=%#x\n", p_arr + 0);
	printf("p_arr+1=%#x\n", p_arr + 1); //指针一次移动一个指针大小，即8byte
	printf("p_arr+2=%#x\n", p_arr + 2);
	printf("**(p_arr+0)=%d\n", **(p_arr + 0));
	printf("**(p_arr+1)=%d\n", **(p_arr + 1));
	printf("**(p_arr+2)=%d\n", **(p_arr + 2));

	printf("\n--------------------1.2指针数组: 存放数组指针-----------------------\n");

	// int *p_arr2[3] = {{1, 2}, {11, 22}};//error
	int arr1[] = {1, 2}, arr2[] = {11, 22};
	// int p_arr2[2][2] = {arr1, arr2};//error
	int *p_arr2[2] = {arr1, arr2};
	printf("*(*(p_arr2+0)+0)=%d\n",*(*(p_arr2+0)+0));
	printf("*(*(p_arr2+0)+1)=%d\n",*(*(p_arr2+0)+1));
	printf("*(*(p_arr2+1)+0)=%d\n",*(*(p_arr2+1)+0));
	printf("*(*(p_arr2+1)+1)=%d\n",*(*(p_arr2+1)+1));

	printf("\n-------------------2.数组指针------------------------\n");
	//arr对应一块内存，而不是指向一块内存;指向一块固定的内存区域，像是指针常量
	int arr[5][3] =
		{
			{11, 12, 13},
			{21, 22, 23},
			{31, 32, 33},
			{41, 42, 43},
			{51, 52, 53}};
	printf("arr=%#x\n", arr);		  //作了处理，所以是第一个元素的地址？
	printf("&arr=%#x\n", &arr);		  //第一个元素的地址
	printf("&arr[0]=%#x\n", &arr[0]); //第一个元素的地址；三者相等

	//不可以这样直接赋值
	// int (*arr_p)[3] = { { 11, 12, 13 }, { 21, 22, 23 }, { 31, 32, 33 }, { 41, 42,43 }, { 51, 52, 53 } };

	//[]的优先级更高，加上()后，就代表arr_p指向int[3]类型指针；arr_p+1跨过3*4个字节，也称行指针
	//本质上还是一个一级指针，只不过指针移位运算一次移动 3*4字节
	//c++中，二级指针好像是专门为二维数组设计的
	// int(*arr_p)[3] = (int(*)[3]) & arr; //ok
	int(*arr_p)[3] = arr;
	printf("&arr = %#x\n", &arr); //相当于第一个元素地址
	printf("arr_p+0 = %#x\n", arr_p + 0);
	printf("arr_p+1 = %#x\n", arr_p + 1); //指针一次移动一行，即3*4byte
	printf("arr_p+2 = %#x\n", arr_p + 2);

	printf("**(arr_p+0)= %d\n", **(arr_p + 0)); //第一行，第一个元素
	printf("**(arr_p+1)= %d\n", **(arr_p + 1)); //第二行，第一个元素
	printf("**(arr_p+2)= %d\n", **(arr_p + 2));
	printf("**(arr_p+3)= %d\n", **(arr_p + 3));
	printf("**(arr_p+4)= %d\n", **(arr_p + 4));
	printf("*((*arr_p+4)+2)=%d\n", *(*(arr_p + 4) + 2)); //第五行，第三个元素

	//	printf("*arr_p =%d\n", *arr_p);
	//	printf("*(arr_p+1)= %d\n", *(arr_p + 1));
	//	printf("*(arr_p+2)=%d\n", *(arr_p + 2));

	return 0;
}
