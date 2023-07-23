/*
 *  Created on: 2019年3月13日
 * 
 * 	malloc: 申请多少个字节
 * 
 * 
 * 	
 *	malloc(): Memory Allocation，分配一个连续堆内存
 *	calloc():Clear Allocation，与malloc的最大区别就是分配后的内存默认初始化清零
 *	realloc():Reset Allocation，给已分配的堆内存重新调整大小
 * 	alloca(): Allocation，分配一个连续栈内存；不过栈的动态分配是由编译器进行释放，无需手工实现
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{

	printf("-------------1.malloc---------------\n");

	int *p = (int *)malloc(sizeof(int) * 3); //stdlib.h,默认返回void*
	*(p + 0) = 0;
	*(p + 1) = 1;
	*(p + 2) = 2;

	printf("p+0 = %#x\n", p + 0);
	printf("p+1 = %#x\n", p + 1);//一次移动4个字节
	printf("p+2 = %#x\n", p + 2);

	printf("p+0 value: %d\n", *(p + 0));
	printf("p+1 value: %d\n", *(p + 1));
	printf("p+2 value: %d\n", *(p + 2));

	printf("\n-------------2.free---------------\n");
	free(p); //释放p所指向的堆内存上的数据

	printf("p+0 value: %d\n", *(p + 0));
	printf("p+1 value: %d\n", *(p + 1));
	printf("p+2 value: %d\n", *(p + 2));
	return 0;
}
