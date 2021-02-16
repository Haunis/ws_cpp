/**
 * 参考：https://blog.csdn.net/qq_40416052/article/details/82493916
 *
 * 用于动态申请内存，申请的是堆内存;
 * 和malloc的区别：
 * 1.new 关键字是c++的一部分，malloc是由c库提供的函数
 * 2.new以具体类型为单位进行内存分配，malloc是以字节为单位进行内存分配
 * 3.new在申请单个变量时可以进行初始化，malloc不具备内存初始化的特性
 *
 */

#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("1.变量申请--------------------------------------------\n");
	int *p = new int;
	*p = 5;
	*p = *p + 10;
	printf("p=%#x, *p=%d\n", p, *p);

	delete p;

	printf("2.数组申请--------------------------------------------\n");
	p = new int[10]; //数组里存放的不是指针，是int类型数据
	for (int i = 0; i < 10; i++) {
//		p[i]=i;
		*(p + i) = i;
		printf("p[%d]=%d\n", i, p[i]); //和*(p+i)一样
	}
	printf("sizeof(p):%d\n", sizeof(p)); //32系统4字节，64系统8字节
	for (int i = 0; i < 10; i++) {
		printf("p+%d=%#x\n", i, p + i); //p每次移动四个字节
	}
	delete[] p;

	printf("3.new关键字初始化--------------------------------------------\n");
	int *pi = new int(1); //动态申请一个int，初始化为1
	float *pf = new float(10);
	char *pc = new char('a');

	int *pi_array = new int[1]; //动态申请一个数组，数组大小为1；和上述pi不一样

	printf("*pi = %d\n", *pi); //1
	printf("*pf = %.3f\n", *pf); //10.000
	printf("*pc = %c\n", *pc); //a
	printf("*pi_array = %d\n", *pi_array); //0

}
