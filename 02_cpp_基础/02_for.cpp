/**
 *	for循环初始化和增值域可以放一条以上语句，中间用逗号隔开.
 *
 * 	增值域就是最后分号隔开的那部分
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	printf("------------------1.普通for循环---------------------\n");
	for (int i = 0, j = 10; i != j; i++, j--)
	{
		printf("i=%d,,,j=%d\n", i, j);
	}

	printf("------------------2.增强for循环---------------------\n");
	//需要c++11支持
	int array[] = {1, 2, 3, 4, 5};
	for (int &i : array)
	// for (auto &i : array)
	{
		printf("%d\t", i);
	}
	return 0;
}
