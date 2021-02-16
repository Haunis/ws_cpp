/**
 *非0即为真
 *
 *逻辑运算符：
 *	与：&&
 *	或：||
 *	非：！
 * 
 * switch: 支持char,int,enum 
 * 		当然也可使用string转hash的骚操作：https://blog.csdn.net/yozidream/article/details/22789147
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	printf("\n--------------------1.if---------------------\n");

	if (2 > 1 && 3 > 2)
	{
		printf("true\n");
	}

	printf("\n--------------------2.switch---------------------\n");
	char c = 'a';
	switch (c)
	{
	case 'a':
		printf("this is a \n");
		break;
	case 'b':
		printf("this is b \n");
	default:
		break;
	}
	return 0;
}
