/**
 *可变参数
 *		参考：https://blog.csdn.net/zhangkai19890929/article/details/82392300
 *			https://blog.csdn.net/al86866365/article/details/56485178
 *			https://blog.csdn.net/u012707739/article/details/80170671
 *
 *1.需要包含头文件 stdarg.h
 *
 *2.对可变参数的操作如 fun(int first,...){}
 *		a. va_list cp //定义一个字符指针
 *		b. va_start(cp,first);//跳过first,将指针指向下一个参数的内存地址
 *		c. va_arg(cp,int);//取出指针指向地址所存的值，并将指针+1
 *		d. va_end(cp);//将指针置为NULL
 */

#include <iostream>
#include <stdio.h>
#include <stdarg.h>

// #define PRINTF(...) printf(__VA_ARGS__) //ok
#define PRINTF(format, args...) printf(format, ##args) //##允许参数args为空

// #define SUM(...) sum(__VA_ARGS__)//ok
// #define SUM(fmt,...) sum(fmt,##__VA_ARGS__)//ok
#define SUM(fmt, args...) sum(fmt, ##args) //ok; ##--允许参数为空
#define SUM2(fmt, args...) sum(fmt, args)  //ok； 不允许参数为空


using namespace std;

int sum(int count, ...)
{
	int total = 0;
	va_list cp;			 //实质是个字符指针 char*
	va_start(cp, count); //把指针cp移动sizeof(first)字节数，指向下一个参数地址

	while (count != 0)
	{
		int element = va_arg(cp, int); //取出cp指针指向的值，并将指针移动到下一个位置
		printf("sum --> %d\n", element);
		total += element;
		count--;
	}
	va_end(cp); //指针置为NULL
	return total;
}

int sum2(int count, int first...)
{
	printf("sum2--> count=%d,first=%d\n", count, first);

	int total = first;
	va_list cp; //实质是个字符指针 char*
	// va_start(cp, count); //
	va_start(cp, first); //把指针cp移动sizeof(first)字节数，指向下一个参数地址
	count--;
	while (count != 0)
	{
		int element = va_arg(cp, int); //取出cp指针指向的值，并将指针移动到下一个位置
		printf("sum2 --> %d\n", element);
		total += element;
		count--;
	}
	va_end(cp); //指针置为NULL
	return total;
}

int main()
{
	printf("-----------------1.1 可变参数只有一个参数名-------------------\n");
	int ret = sum(4, 1, 2, 3, 4);
	printf("ret = %d\n", ret);

	printf("\n---------------1.2 可变参数有2个参数名-------------------\n");
	ret = sum2(4, 1, 2, 3, 4);
	printf("ret = %d\n", ret);

	printf("\n-------------------2.可变参数宏-------------------\n");
	PRINTF("可变参数，name:%s\n", "haha");
	PRINTF("可变参数，hello\n");

	printf("\n-----------------3.1 可变参数宏SUM(fmt,args...)sum(fmt,##args)--------\n");
	ret = SUM(1); //ok; 参数为空时##去掉前面逗号
	ret = SUM(3, 1, 2, 3);
	printf("ret = %d\n", ret);

	printf("\n-----------------3.2 可变参数宏SUM2(fmt, args...) sum(fmt, args)-------\n");
	// ret = SUM2(1);//error; 无##不允许参数为空
	ret = SUM2(3, 1, 2, 3);
	printf("ret = %d\n", ret);
	return 0;
}
