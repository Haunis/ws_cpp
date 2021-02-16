/*
 * MainMallocRealloc.c
 *
 *  Created on: 2019年3月13日
 *      Author: BTI-PC
 *
 *	演示malloc和realloc函数的用法
 *
 *	realloc函数做所的工作:
 *		1.重新申请内存
 *		2.此函数会在旧内存的后面去扩展空间。
 *			如果旧内存空间被占用了，那么不能扩展；此时会寻找一个新的足够大的空间，重新申请内存
 *			申请完毕后会把旧内存数据复制到新内存中区
 *		3. 释放旧的内存
 *	
 *	使用c/c++ compile and run插件,按f7,填入-std=c11
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("输入学生数量 count :");
	int count;
	scanf("%d", &count);

	int *p = (int *)malloc(sizeof(int) * count);//申请堆内存用于存储学生id

	for (int i = 0; i < count; i++) //c11标准
	{
		printf("please enter student %d ID: ", i + 1);
		scanf("%d", (p + i));
	}

	//新来了几个学生
	int newCount;
	printf("please enter new student num :");
	scanf("%d", &newCount);

	p = realloc(p, sizeof(int) * (count + newCount));
	for (int i = 0; i < newCount; i++)
	{
		printf("please enter new student %d ID : ", i + 1);
		scanf("%d", (p + i + count));
	}

	//打印结果
	for (int i = 0; i < count + newCount; i++)
	{
		printf("student %d id %d\n", i + 1, *(p + i));
	}

	system("pause");
	return 0;
}
