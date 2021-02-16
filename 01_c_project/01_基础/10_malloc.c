/*
 *  Created on: 2019年3月13日
 * 
 * 	malloc: 申请多少个字节
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
