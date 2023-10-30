
https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html


背景知识：
	1. gcc编译函数和g++编译处理方式是不一样的:
			g++编译函数是会给函数加上"_"和参数类型,如:add(int,int)处理成"_Z3addii"
			gcc编译函数不会处理函数名,add(int,int)编译后还是 "add"
		因此：
			g++编译后的代码到gcc编译后的.o文件寻找函数会找不到
			反之,gcc编译后的到g++编译后的.o文件找也找不到
	2. gcc编译c文件按C语言风格，编译cpp文件按c++风格； g++编译c和cpp文件都是按c++风格
	3. C语言不支持extern "C"声明(gcc编译c文件时不支持)


extern "C"实现混合编程
	1. cpp代码调用.c代码
		1) 如果cpp文件和c文件都是用g++编译的，编译后直接链接就行，反正都是c++风格；
		2) 如果c文件是使用gcc编译的，那么直接链接会报错，因为c++找不到对应的函数
		   因为，c++要找的是"_Z3addii",但c文件编译后提供的是"add"。

		   此时只需要在cpp文件添加extern "C" int add(int x, int y)即可，表示告诉g++编译器找的是"add"

		   处理方式1： 
		   		直接在cpp文件声明要调用的c函数即可: extern "C" int add(int x, int y)
		   处理方式2：
		   		cpp文件包含c的头文件时声明extern "C"，该处理方式其实是和处理方式1是等价的： 
				extern "C"{
					#include "xxx.h"
		   		}
			c文件和其对应的头文件不用改。
	2. c代码调用cpp代码
		1) 如果cpp文件和c文件都是用g++编译的，编译后直接链接就行，反正都是c++风格；
		2) 如果都是用gcc或者c文件用gcc，cpp文件用g++，那么编译后链接会报错
			处理方式：
				把cpp文件按c语言风格进行编译就行，其对应的头文件加不加extern "C"都行(建议加上)。
				但cpp文件的函数实现必须加上extern"C":
				extern "C" 
				int add(int x,int y){
					...
				}

			c文件声明所调用的函数在外部即可： extern int add(int x, int y); 

	总结： 
		1. cpp调用c
			c文件和对应的头文件不用改。
			cpp文件： 
				调用函数前，必须声明调用的C函数是 extern "C"的；
				具体实现方式有两种：1.调用前在函数前声明extern "C" 2.extern "C"{C的头文件}
		2. c调用cpp:
			c文件： 不支持extern "C"声明，所以可以直接c文件可以：
				1.什么都不用做，但编译是会warning提示函数是implicit的  2.extern func()...告诉编译器函数在别处定义
			extern int add(int x, int y); 
			cpp文件：
				函数声明是extern "C"的：
				extern "C" 
				int add(int x,int y){
					...
				}
			cpp头文件：extern "C" int add(int x,int y); //当然也可以不加extern "C"

			
		  

	
在添加extern "C"和不添加 extern "C"的情况下使用 g++ -S main.cpp生成两个main.s
比较两个main.s,可知添加extern "C"后,编译后的变量是按C的方式处理的

g++ -S : 只编译,不汇编,不链接,生成.s文件里面是汇编指令
