
https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html

extern "C"实现混合编程:
	.cpp文件默认用g++编译,.c文件默认用gcc编译
	如果用g++将两者编译后的.o中间文件直接链接的话,会链接错误

	因为gcc编译函数和g++编译处理方式是不一样的:
		g++编译函数是会给函数加上"_"和参数类型,如:add(int,int)处理成"_Z3addii"
		gcc编译函数不会处理函数名,add(int,int)编译后还是 "add"

	g++编译后的代码到gcc编译后的.o寻找函数会找不到;
	反之,gcc编译后的到g++编译后的找也找不到

	cpp代码调用.c代码示例:
		使用extern "C"引入.c代码对应的头文件即可
		如 extern "C"{
			#include "xxx.h"
		   }
	.c代码调用cpp代码:
		不可直接include cpp的头文件,而是要修改cpp的头文件
		cpp头文件加上 extern "C"修饰,如 extern "C" int add(int x,int y);
	
	
在添加extern "C"和不添加 extern "C"的情况下使用 g++ -S main.cpp生成两个main.s
比较两个main.s,可知添加extern "C"后,编译后的变量是按C的方式处理的

g++ -S : 只编译,不汇编,不链接,生成.s文件里面是汇编指令
