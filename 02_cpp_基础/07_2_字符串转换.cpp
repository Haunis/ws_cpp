/*
 *
 *1.string转char*:
 *		1.string.data()
 *		2.string.c_str()
 *		3.str.copy(char[],0,5)
 *		参考: https://www.cnblogs.com/wuruofeng/p/10412559.html
 *
 * 2.int转string
 * 		string s = std::to_string(int x)
 * 
 * 3.string 转 int ,float等等
 * 		stringstream(string ss) >> ret  
 * 		stringstream是一个类
 * 		将string类型的变量转换成其他如int ,float类型的变量
 *
 * 4.char arr[]转int
 *		int x = atoi(arr)
 *
 */

#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

	printf("\n---------------1.string转char*----------------------------\n");
	string ss = "hello";
	//	const char *char_p = ss.data();
	char *char_p = (char *)ss.data();								   //转换后就是一个普通指针
	printf("char_p=%s, sizeof(char_p)=%lu\n", char_p, sizeof(char_p)); //size是8,指针

	*char_p = 'x'; //不是常量指针，可以为里面的内容重新赋值
	printf("char_p=%s\n", char_p);

	printf("\n---------------2.int转string: std::to_string(int)-----------------------\n");
	int count = 100;
	string str_count = std::to_string(count);
	printf("str_count = %s\n", str_count.data());

	printf("\n---------------3.string转int: stringstream(ss)>>int-----------------------\n");
	string ss3 = "3";
	int ret3;
	stringstream(ss3) >> ret3;
	printf("ret3 = %d\n", ret3);

	printf("\n---------------4.char[]转int: atoi(char[])----------------------------\n");
	char c_num[4] = "10";
	int i_num = atoi(c_num);
	int l_num = atol(c_num);
	float f_num = atof(c_num);
	printf("i_num=%d\n", i_num);
	printf("l_num=%d\n", l_num);
	printf("f_num=%.2f\n", f_num);

	printf("\n---------------5.1 数字转char----------------------------\n");
	//0~9转char
	int a5 = 8;
	char char_a5 = a5 + '0';
	printf("char_a5 = %c\n", char_a5);
	
	printf("\n---------------5.2 int转char----------------------------\n");

	int a52 = 1000;
	char char_p52[5];
	sprintf(char_p52,"%d",a52);
	printf("char_p52=%s\n", char_p52);



	
}
