
https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html

C语言不支持extern "C"声明



extern "C"实现混合编程:
	.cpp文件默认用g++编译,.c文件默认用gcc编译
	如果用g++将两者编译后的.o中间文件直接链接的话,会链接错误

	因为gcc编译函数和g++编译处理方式是不一样的,g++编译后的代码到
	gcc编译后的.o寻找函数会找不到;反之,gcc编译后的到g++编译后的找也找不到

	cpp代码调用.c代码:
		使用extern "C"引入.c代码对应的头文件即可
		如 extern "C"{
			#include "xxx.h"
		   }
	.c代码调用cpp代码:
		不可直接include cpp的头文件,而是要修改cpp的头文件
		cpp头文件加上 extern "C"修饰,如 extern "C" int add(int x,int y);
	
	
