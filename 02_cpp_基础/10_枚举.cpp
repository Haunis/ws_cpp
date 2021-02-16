/**
 * 可以在程序里直接访问枚举
 * 可以为枚举赋值,赋值后,其后按顺序依次+1
 */
#include <iostream>
#include <stdio.h>
#include "data.h"
using namespace std;

int main()
{

	printf("--------------------1.Color------------------------\n");
	printf("red=%d\n", red); //0; 可以直接使用枚举
	Color color;//color是个枚举变量
	printf("color = %d\n", color); //未初始化,随机分配数值
	color = green;
	if (color == green)
	{
		printf("in color=%d\n", color); //1
	}

	myColor = black;//myColor也是枚举变量
	printf("my_Color = %d\n", myColor); //301

	printf("\n--------------------2.Config------------------------\n");

	Config config;
	config = CONFIG_1;
	printf("config = %d\n", config);   //100
	printf("CONFIG_2=%d\n", CONFIG_2); //200

	My_Config my_config; //My_Config表示枚举类型，my_config表示枚举变量
	// my_config = 100; //error;不能将常量赋值给枚举变量
	my_config = CONFIG_1;
	printf("myData=%d\n", my_config); //100
	return 0;
}
