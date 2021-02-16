/**
 * 参考:
 * 	https://blog.csdn.net/sksukai/article/details/105612235
 *
 * 变量在使用前必须先定义
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "compute.h"
#include "test_demo.h" //在"compute.h"后面include,所以可以调用compute里的方法

extern int i; //在外部定义
int main()
{
	int addResult = add(7, 8);
	int multiResult = multi(7, 8);
	printf("7 + 8 = %d\n", addResult);
	printf("7 * 8 = %d\n", multiResult);

	printf("i = %d\n", i);

	int count;				//extern 尽量在程序外部使用，用于全局变量
	/*extern */ count = 18; //extern只可以在函数外部进行初始化
	printf("count = %d\n", count);

	//	test_fun();
	printf("\n----------------test_demo start-------------------\n");
	print_test();
	printf("----------------test_demo end-------------------\n");
	printf(
#include "str.h" //#include只是简单地把文件进行替代
	);
}
