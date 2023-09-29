#include <stdio.h>

//引入了add.h头文件后，add.cpp按c语言的风格进行编译，add函数名就是add,不是cpp风格的_Z3addii
// #include "add.h"
// int add(int x, int y)
// {
// 	printf("cpp : add called x=%d,y=%d\n",x,y);
// 	return x+y;
// }



extern "C"  //这样写也行！！！支持C语言
int add(int x,int y){
	printf("cpp : add called x=%d,y=%d\n",x,y);
	return x+y;
}
