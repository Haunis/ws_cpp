/**
 * 参考：https://blog.csdn.net/qq_40416052/article/details/82493916
 *
 * 用于动态申请内存，申请的是堆内存;
 * 
 * new和malloc的区别：
 * 		1.new，delete关键字是c++的一部分，不是函数； malloc是由c库提供的函数
 * 		2.new以具体类型为单位进行内存分配，malloc是以字节为单位进行内存分配
 * 		3.new在申请单个变量时可以进行初始化，如string *s = new string("hello")，
 * 			malloc不具备内存初始化的特性,但calloc可以将元素初始化为0
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("-------------------1.变量申请-------------------------\n");
	int *p = new int;
	*p = 5;
	printf("p=%#x, *p=%d\n", p, *p);

	delete p;

	printf("\n-----------------2.数组申请---------------------------\n");
	p = new int[10]; //数组里存放的不是指针，是int类型数据
	for (int i = 0; i < 10; i++)
	{
		// p[i] = i;//ok;这种方法也行
		*(p + i) = i;
		printf("p+%d=%#x  %d\n", i, p + i, p[i]); //指针每次移动4个字节
	}

	delete[] p;

	printf("\n------------------3.new关键字初始化------------------------\n");
	int *pi = new int(1); //动态申请一个int，初始化为1;注意和new int[1]区别
	float *pf = new float(10);
	char *pc = new char('a');

	printf("*pi = %d\n", *pi);	 //1
	printf("*pf = %.3f\n", *pf); //10.000
	printf("*pc = %c\n", *pc);	 //a

	delete pi;
	delete pf;
	delete pc;
}
