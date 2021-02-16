/*
 *  Created on: Mar 15, 2020
 *      Author: haunis
 *
 *参考：https://www.linuxidc.com/Linux/2013-11/93010.htm
 *
 *一、编译生成so动态库
 *   编译当前目录的add.cpp生成libadd.so动态库
 *   g++ add.cpp -shared -o libadd.so
 *
 *二、链接使用libadd.so
 *   g++ main.cpp -ladd -o main
 *   -ladd：编译器查找动态链接库时有隐含的命名规则--即在给出的名字前面加上lib，名字后面加上.so，即libadd.so
 *   链接时候会自动到/lib或者/usr/lib找add.so,所以应该将生成的动态链接库libadd.so拷贝至/lib或者/usr/lib
 *
 *   补充：使用带其他参数的编译方式
 *   g++ main.cpp -L./math -I./math -ladd -o main
 *   -L./math：-L后跟连接库的路径，‘./math’表示要连接的库所在目录
 *    -I./math：表示要连接的头文件所在目录
 *
 *三、查看可执行文件的动态库依赖关系
 *   ldd test
 *
 * *Eclipse配置动态链接库：
 *	本project→c/c++build→settings→GCC C++ Linker→Libraries→上方添加"add"
 *	编译使用的指令是默认带了-l，所以加上add之后就是 -ladd，即链接libadd.so
 *	因为动态链接库要到/lib或者/usr/lib寻找，所以要将libadd.so拷贝至/lib或/usr/lib
 *	或者引入新的环境变量指向动态链接库libadd.so的路径
 */
#include<stdio.h>
#include"../lib/add.h"
int main(int argc, char *argv[]) {
	int x = 2, y = 6;
	int result = add(x, y);
	printf("%d + %d = %d\n", x, y, result);
	return 0;
}
