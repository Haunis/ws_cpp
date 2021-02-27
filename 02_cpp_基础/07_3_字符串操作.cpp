/*
 *
 *	6.字符串拼接
 *		参考：https://blog.csdn.net/qq_43298454/article/details/90813243
 *	
 * 	string.npos:表示不存在的位置
 *
 */

#include <iostream>
#include <typeinfo>
#include <string.h> //strcpy
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define STRING(x) #x //字符串化操作，就是在首尾加上双引号
// #define SEPARATOR STRING(-)//ok
#define SEPARATOR "-"

using namespace std;

void stringSplit(string s, string separator, vector<int> &ans);

int main()
{
	printf("\n------------------1.strcpy(char*,const char *)----------------------------\n");
	string ss = "hello";
	char char_arr[10] = "abc";
	printf("before char_arr=%s, sizeof(char_arr)=%lu\n", char_arr, sizeof(char_arr)); //hhhhhhhhh;10
	strcpy(char_arr, ss.data());													  //字符串复制; string.h头文件函数
	printf("after char_arr=%s, sizeof(char_arr)=%lu\n", char_arr, sizeof(char_arr));  //hello;10
	printf("*char_arr=%c\n", *char_arr);											  //h

	const char *char_p = "hello";
	// strcpy(char_p, ss.data()); //可以编译通过,但运行时出错; 常量中内容不可修改(char_p指向的一块区域是常量)

	printf("\n-------------------2.1字符串拼接，纯C风格 sprintf-------------------------------------\n");
	const char *s = "lee";
	int s1 = 20;
	float s2 = 1.2345;
	//	char *buf = new char[strlen(s) + sizeof(s1) + 1];
	char *buf = new char[1];
	sprintf(buf, "%s%d%.4f", s, s1, s2);
	printf("字符串拼接，s=%s,s1=%d,s2=%.4f --> ret=%s\n", s, s1, s2, buf);

	printf("\n-------------------2.2 字符串拼接，c++11 使用--------------------------------------\n");
	string str1 = "aaa";
	string str2 = "bbb";
	string str3 = std::to_string(10);
	string ret = str1 + str2 + str3;
	printf("字符串拼接，c++11 : %s\n", ret.data());

	printf("\n-------------------3.1 字符串切割,strtok-------------------------------------\n");
	string origin = "1,2*3,4,5";
	const char *c_origin1 = origin.data();
	printf("c_origin1: %s\n", c_origin1);
	char c_origin2[] = "1,2*3,4,5";

	const char *sep = ",*"; //可按多个字符来分割
	char *sp;
	//	sp = strtok(c_origin1, sep);//报错； invalid conversion from ‘const char*’ to ‘char*’
	sp = strtok(c_origin2, sep);
	while (sp)
	{
		printf("%s ", sp);
		sp = strtok(NULL, sep);
	}
	printf("\n");

	printf("\n-------------------3.2 字符串切割,c++ 11-------------------------------------\n");
	//	string my_origin = to_string(10) + SEPARATOR + to_string(20);
	//	string my_origin = to_string(10) + SEPARATOR;
	string my_origin = to_string(10) + SEPARATOR + to_string(true);
	printf("my_origin: %s\n", my_origin.data());
	vector<int> my_vector;
	//	stringSplit(my_origin, SEPARATOR, my_vector);//ok
	//	stringSplit(my_origin, "-", my_vector);//ok
	stringSplit(my_origin, SEPARATOR, my_vector); //ok
	for (int i = 0; i < my_vector.size(); i++)
	{
		printf("ret --> %d \n", my_vector[i]);
	}
	printf("\n");

	if (0)
	{
		printf("iniiiiii \n");
	}
}

void stringSplit(string s, string separator, vector<int> &ans)
{
	string::size_type pos_1, pos_2 = 0;
	while (pos_2 != s.npos)
	{
		pos_1 = s.find_first_not_of(separator, pos_2); //pos_2表示从该位置开始搜索
		if (pos_1 == s.npos)
			break;
		pos_2 = s.find_first_of(SEPARATOR, pos_1);
		printf("pos_1=%ld,pos_2=%ld\n", pos_1, pos_2);
		ans.push_back(atoi(s.substr(pos_1, pos_2 - pos_1).c_str())); //substr(0,-1);截取全部
	}
}
