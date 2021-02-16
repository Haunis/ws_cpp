/*
 * https://www.cnblogs.com/bluecagalli/p/9511126.html
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

	printf("\n------------------1.1 标准方式1: int arr[][]---------------\n");
	int arr[HEIGHT][WIDTH]; //二维数组
	//赋值
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			arr[i][j] = i * 10 + j; //为每行赋值
		}
	}
	//打印
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n------------------1.2 标准方式2: int arr[][]={}---------------\n");
	int arr2[9][9] = {{1, 2}, {3}}; //arr2[0][0,1]和arr2[1][0]的值初始化，其他初始化为0
	printf("arr2[0][1]=%d\n", arr2[0][0]);//1
	printf("arr2[0][1]=%d\n", arr2[0][1]);//2

	printf("\n------------------2.1 指针方式1: int(*arr_p)[3]=new[][]---------------\n");
	//数组指针；[]的优先级更高，加上()后，就代表arr_p指向int[3]类型指针；
	//arr_p+1跨过3*4个字节，也称行指针
	int(*arr_p)[3] = new int[10][3];
	printf("arr_p+0 = %#x\n",arr_p+0);
	printf("arr_p+1 = %#x\n",arr_p+1);//指针一次移动一行，即3*4 = 12byte
	printf("arr_p+2 = %#x\n",arr_p+2);

	printf("\n------------------2.2 指针方式2: int **pp = new int *[HEIGHT]-------------\n");
	int **pp = new int *[HEIGHT]; //指针数组，数组里存放HEIGHT个指针;
	// int(*bean)[WIDTH] = (int(*)[WIDTH]) & arr;//ok; 将二维数组强转为行指针
	int(*bean)[WIDTH] = arr;
	for (int i = 0; i < HEIGHT; i++)
	{
		*(pp + i) = new int[WIDTH]; //pp每个指针存放一个一级数组
									//	*(pp + i) = *(bean + i);
		for (int j = 0; j < WIDTH; j++)
		{
			*(*(pp + i) + j) = *(*(bean + i) + j);
		}
	}
	printf("二级指针指向的内存区域存储的值 --->\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%d\t", *(*(pp + i) + j));
		}
		printf("\n");
	}


	return 0;
}
