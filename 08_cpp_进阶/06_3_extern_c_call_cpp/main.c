#include <stdio.h>

// #include "add.h"//error,不能直接包含cpp的头文件
// int add(int x,int y);//ok; 不加extern野性
extern int add(int x, int y);

int main(int arg, char *argv[])
{
	int ret = add(3, 4);
	printf("main ret=%d\n", ret);
	return 0;
}
