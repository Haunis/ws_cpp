/**
 * 参考：
 *      https://blog.csdn.net/yby4769250/article/details/7359278
 * 
 * 常量折叠就是，在编译阶段，对该变量进行值替换。
 * 类似宏定义，但是和宏不同的是常量会分配内存
 * 
 * 输出带源代码的汇编文件：
 *	https://www.cnblogs.com/fengkang1008/p/4652193.html
 *	1.生成.o文件和.s文件
 *		g++ -g -c 01_常量折叠.cpp 
 *	2.生成含有调试信息，cpp源码的汇编代码
 *		objdump -S 01_常量折叠.o >dump.s
 */
#include <iostream>
#include <stdio.h>

#define PI 3.14
int main()
{
    const int r = 10;

    int p = PI;      //这里会在预编译阶段产生宏替换，PI直接替换为3.14，其实就是int p = 3.14;
    int len = 2 * r; //这里会发生常量折叠，也就是对常量r的引用会替换成他对应的值，相当于int len = 2*10;


    const int i = 0;                          //定义常量i,i会有自己的栈空间
    int *j = (int *)&i;                       //看到这里能对i进行取值，判断i必然有自己的内存空间
    *j = 1;                                   //对j指向的内存进行修改
    printf("%d\n%d\n%d\n%d\n", &i, j, i, *j); //&i和j相同，说明地址相同； i和*j不同，说明i已被替换


    const int ck = 9;                         //这个对照实验是为了观察，对常量ck的引用时，会产生的效果
    int ik = ck;                              //对常量的应用,会直接替换为常量的值9

    int i1 = 5;
    int i2 = i1; // 对变量i1引用没有替换成i1的值，而是去栈中先取出i1的值，
                 // 到edx寄存器中，然后再把值mov到i2所在的内存中

    return 0;
}