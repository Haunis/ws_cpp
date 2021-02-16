/*
 *  Created on: Mar 15, 2020
 *      Author: haunis
 *
 *参考：https://blog.csdn.net/sxj731533730/article/details/84345505
 *
 *
 *静态链接库的生成和使用
 *生成：
 *	1.在要编译成静态库的文件夹(math)生成目标文件
 *		g++ add.cpp -c -o add.o
 *	2.根据生成的目标文件生成静态库文件
 *		ar -crv libadd.a add.o (-c：创建; -r:向add.a插入add.o; -v:附加信息)
 *
 *使用：
 *	1.在要使用静态的文件目录生成目标文件
 *		g++ main.cpp -c -o main.o
 *	2.将生成额目标文件和静态库文件链接起来
 *		g++ main.o math/libadd.a -o main
 *
 *Eclipse配置静态链接库：
 *	本project→c/c++build→settings→GCC C++ Linker→Miscellaneous→Other objects，加入静态库路径
 *
 */

#include<iostream>
#include"../math/add.h"

using namespace std;
int main() {
	int a = 3, b = 4;
	int result = add(a, b);//调用静态库libadd.a的方法
	printf("%d + %d = %d\n", a, b, result);
}
