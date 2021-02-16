/**
 * 1.声明和定义的区别:
 *  	一个变量在使用前必须先定义(定义会分配内存空间,声明不会)
 *  	变量可以被声明多次,但只能定义一次
 *		extern int x; //声明一个全局变量
 *		extern int x = 0; //定义全局变量并给初值
 *		int x; //声明并定义一个全局变量,默认值0
 *  	int x = 0; //声明并定义全局变量,并给初值
 * 
 * 2.extern和static:
 * 		https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html
 * 		extern :
 * 			就是告诉编译器该变量可以在别的模块定义
 * 			作用1: 头文件使用. 告诉编译器，其声明的函数和变量可以在本模块或其它模块中使用(如outer_modle.h 中的 extern int a)
 * 			作用2: 当前模块使用. 告诉编译器,当前模块只声明不定义,变量在其他模块定义
 *
 * 		static:
 * 			和extern相对应,被它修饰的全局变量和函数只能在本模块中使用
 *
 *
 * 3.extern C
 * 		参考：
 *			https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html
 *			https://www.cnblogs.com/xiangtingshen/p/10980055.html
 *			https://blog.csdn.net/qq_30891813/article/details/87631651
 *
 * 		extern "C"指令中的C，表示的一种编译和连接规约，而不是一种语言。
 * 		C表示符合C语言的编译和连接规约的任何语言，如Fortran、assembler等。
 * 		如果有很多语言要加上extern "C"，可以将它们放到extern "C"{ }中。
 *
 * 		extern "C"的真实目的是实现类C和C++的混合编程
 * 		在C++源文件中的语句前面加上extern "C"，表明它按照类C的编译和连接规约来编译和连接，而不是C++的编译的连接规约
 * 		这样在类C的代码中就可以调用C++的函数or变量等
 *
 */

#include <iostream>
#include "outer_module.h"

using namespace std;

//可以省略此处a的声明,因为outer_module.h已经声明.
//编译阶段虽然找不到该变量,但不会报错,链接阶段会在outer_module.cpp编译生成的目标代码中寻找该变量
extern int a;

//不能省略b的声明,因为包含的outer_moule.h头文件并无b的声明
extern int b; //声明但不定义。要使用的话必须要定义(本例中已在outer_module.cpp定义)
extern int b; //可以声明多次

// int a; //error;全局变量,声明并定义,默认值是0; outer_module.cpp已经定义过了,不可在此再次定义
int main()
{
	cout << "a = " << a << endl;
	cout << "b =  " << b << endl;

	fuction(10);

	return 0;
}
