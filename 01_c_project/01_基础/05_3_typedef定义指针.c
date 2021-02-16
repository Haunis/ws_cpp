/*
 *  Created on: 2019年3月13日
 * 	Author: BTI-PC
 *
 * 	指针可以指向变量，也可以指向函数
 *
 * 	typedef 给函数起别名:https://www.cnblogs.com/myyan/p/4710346.html
 */

#include<stdio.h>
#include<stdlib.h>
void printHello()
{
	printf("printHello executed \n");
}
int sum(int x, int y)
{
	return x + y;
}

typedef int (*My_Sum)(int x, int y);

My_Sum test(){
	printf("test called \n");
	return sum;
}

int main()
{
	printf("sum:%#x\n", (unsigned int)(long)sum);
	printf("&sum:%#x\n", (unsigned int)(long)&sum);//这两个值相等....

	My_Sum my_sum = &sum;//用sum或者&sum都行，这两个值相等
	int ret = my_sum(3, 4);
	printf("my_sum(3, 4)=%d\n", ret);

	int (*p_sum)(int x, int y);//定义函数指针 
	p_sum = sum;
	ret = p_sum(3, 4);
	printf("p_sum(3, 4)=%d\n", ret);

	printf("\n----------函数返回函数指针----------\n");
	ret = test()(3,4);
	printf("ret=%d\n", ret);

	return 0;
}

