/**
 *  Created on: 2019年3月14日
 *
 *	1.memcpy:
 *		https://blog.csdn.net/m0_53157173/article/details/113826636
 *		函数原型： void *memcpy(void*dest, const void *src, size_t n);
 *				  从src 拷贝n个字节到 dest中
 *		与strcpy相比，memcpy遇到’\0’不结束，而且一定会复制完n个字节。
 *		只要保证src开始有n字节的有效数据，dest开始有n字节内存空间就行。
 *		头文件：string或者memory
 *
 *  2、strcpy、sprintf 与memcpy 的区别:
 * 		1.操作对象不同，
 * 			strcpy 的两个操作对象均为字符串;
 * 			sprintf 的操作源对象可以是多种数据类型， ⽬的操作对象是字符串
 * 			memcpy 的两个对象就是两个任意可操作的内存地址，并不限于何种数据类型
 * 		2.执⾏效率不同
 * 			memcpy > strcpy > sprintf
 * 		3.实现功能不同，
 * 			strcpy 主要实现字符串变量间的拷⻉
 * 			sprintf 主要实现其他数据类型格式到字 符串的转化
 *			memcpy 主要是内存块间的拷⻉
 * 
 *	3.memset:
 *		https://blog.csdn.net/m0_53157173/article/details/113826636
 *		函数原型： extern void *memset(void *buffer, int c, int count) 
				 将buffer中count个字节使用c替代
 *		头文件：string或者memory
 *
 *  4、类型转换
 * 		1.整型转换成字符串：
 *  		sprintf(char_arr,"%d%d%.2f",a1,a2,a3);//将整型a1和a2，浮点型a3存储到字符数组char_arr里
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //malloc, memcpy

int main()
{
	int apply_mem_size = 10;
	char *from = "hello_word";

	char dest[apply_mem_size];
	char *p_dest = (char *)malloc(apply_mem_size); // 申请10个字节的内存; stdlib.h; 默认返回void*

	printf("\n----------------1.1 sprintf 复制-------------------\n");
	sprintf(dest, "%s", from);
	printf("dest : %s\n", dest); // hello_word

	sprintf(p_dest, "%s", from);
	printf("p_dest : %s\n", p_dest); // hello_word

	printf("\n----------------1.2 sprintf 字符串拼接-------------------\n");

	sprintf(dest, "%d%c", 100, 'a'); //  %#x是十六进制
	printf("dest : %s\n", dest);	 // 100a

	sprintf(p_dest, "%d%c", 200, 'b'); // %#x是十六进制
	printf("p_dest : %s\n", p_dest);   // 200b

	printf("\n----------------2.strcpy字符串复制-------------------\n");
	strcpy(dest, "han");
	printf("dest : %s\n", dest);

	strcpy(p_dest, "han");
	printf("p_dest : %s\n", p_dest);

	printf("\n----------------3.memcpy 内存复制-------------------\n");
	char *tmp_from = "abcde";

	memset(dest, '\0', sizeof(dest));		  // 重置dest数组，否则dest后面的元素会依然存在
	memcpy(dest, tmp_from, strlen(tmp_from)); // 这里用strlen，sizeof在这得到的是指针长度.
	printf("dest : %s\n", dest);

	memset(p_dest, '\0', apply_mem_size); //重置申请的堆内存
	memcpy(p_dest, tmp_from, strlen(tmp_from));
	printf("p_dest : %s\n", p_dest);

	free(p_dest);
	return 0;
}
