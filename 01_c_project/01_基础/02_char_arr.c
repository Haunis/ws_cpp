/*
 *  Created on: 2019年3月14日
 *
 *  整型转换成字符串：
 *  sprintf(char_arr,"%d%d%.2f",a1,a2,a3);//将整型a1和a2，浮点型a3存储到字符数组char_arr里
 *
 *  可参考：cpp工程“1_2_char_arring和常量”
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //malloc

int main()
{

	printf("\n----------------1.strcpy字符串复制-------------------\n");
	char name[50];
	printf("name before : %s\n", name);
	strcpy(name, "Han");
	printf("name after  : %s\n", name);

	printf("\n----------------2.sprintf字符串拼接-------------------\n");
	char *char_p = (char *)malloc(12); //stdlib.h; 默认返回void*


	char char_arr_dest[10];

	sprintf(char_arr_dest, "%d%c", 100, 'a'); //使用sprintf(); %#x是十六进制

	printf("char_arr : %s\n", char_arr_dest);
	return 0;
}
