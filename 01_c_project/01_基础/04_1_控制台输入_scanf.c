/**
 *  Created on: 2019年3月13日
 * 
 * 格式说明
 * 	%c  - char
 *	%d  -  int
 *	%ld -long int
 *	%lu -long unsigned int
 
 *	%lld - long long
 *	%hd - 短整型
 *	%f -  float
 *	%lf - double
 *	%u - 无符号数
 *	%x - 十六进制输出int 或者long  int 或者short int
 *	%o -  八进制输出
 *	%s - 字符串

 *  %#x - 输出了16进制地址； (unsigned int)(long)
 * 
 * 本demo不能使用Code Runner插件，，使用c/c++ compile run 按f6
 *
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int age;
	printf("int地址接收，请输入age:	\n");
	scanf("%d", &age); //&是取地址符；将控制台输入的数值赋值个&age内存

	char name[4];
	printf("字符数组地址接收，请输入name:	\n");
	// scanf("%s", &name);
	scanf("%s", name);

	printf("num: %d, name: %s\n", age, name);

	printf("age address: %#x\n", (unsigned int)(long)&age); //#用于显示在输出结果前面区分进制 ;占用的相对地址不会重新分配
	printf("name address : %#x\n",(unsigned int)(long) &name);

	system("pause");
	return 0;
}

