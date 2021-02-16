/**
 *	-S:只编译,不汇编,不链接,生成.s文件里面是汇编指令,可用cat查看
 *		如: g++ -S main.cpp 
 *
 *	使用g++ -S 查看编译后的.s文件可知:
 *		add(int,int)编译成:_Z3addii:
 *		add(float,float)编译成:
 *
 *	C语言不支持函数重载
 *  函数重载是发生在编译阶段
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


int add(int i, int j = 2)
{
	return i +j;
}
float add(float i, float j)//C语言不支持重载
{
	return i + j;
}

int main()
{
	
	int int_ret = add(2, 3);
	float float_ret = add(2.5f, 3.5f);
	
	printf("int_ret = %d\n",int_ret);
	printf("float_ret = %.2f\n",float_ret);
	
	//	system("pause");
	return 0;
}

