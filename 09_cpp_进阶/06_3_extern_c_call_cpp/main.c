#include <stdio.h>

// #include "add.h"//error; C语言不支持extern "C"声明; 如果头文件里没有extern "C"的话，可以include
// int add(int x,int y);//ok; 不加extern也行
// extern "C" int add(int x, int y); //error; C语言不支持extern "C"声明
extern int add(int x, int y); //ok; 不要这行也行！不过在编译时有warning

int main(int arg, char *argv[])
{
	int ret = add(3, 4);
	printf("main ret=%d\n", ret);
	return 0;
}
