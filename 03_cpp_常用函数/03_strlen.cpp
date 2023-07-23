/**
 *  strlen:要引入string.h
 *
 *	c++会在字符常量如"hello"加上'\0作为'结束, 但不会给字符数组如{}加上
 *
 *  strlen和sizeof区别:
 *  	strlen:	获取char*和char[]定义的字符串长度,不算'\0'
 *  	sizeof: 计算的是数据类型占内存的⼤⼩；char*获取的是指针大小;
 *
 * 		1. sizeof是⼀个操作符，strlen是库函数。
 * 		2. sizeof的参数可以是数据的类型，也可以是变量，⽽strlen只能以结尾为‘\0’的字符串作参数。
 * 		3. 编译器在编译时就计算出了sizeof的结果，sizeof计算的是数据类型占内存的⼤⼩
 * 		   ⽽strlen函数必须在运⾏时才能计算出来,strlen计算的是字符串实际的⻓度
 * 		4. 数组做sizeof的参数不退化，传递给strlen就退化为指针了
 *
 * 		举例：
 * 				类型											strlen				sizeof
 * 			char* s1="hello"									5					8
 * 			char s2[] = "hello"									5					6
 * 			char s3[] = {'h', 'e', 'l', 'l', 'o', '\0'};		5					6
 * 			char s4[5] = {'h', 'e', 'l', 'l', 'o'};				10					5
 *
 */
#include <iostream>
#include <stdio.h>
#include <string.h> //strlen

using namespace std;

int main()
{
	// char *s1 = "hello"; //ok；但编译器会warning
	const char *s1 = "hello";
	char s2[] = "hello";
	char s3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char s4[5] = {'h', 'e', 'l', 'l', 'o'};

	printf("s1=%s, strlen(s1)=%ld\n", s1, strlen(s1)); // 5
	printf("s1=%s, sizeof(s1)=%ld\n", s1, sizeof(s1)); // 8 -- 实际大小，这里是指针大小

	printf("\ns2=%s, strlen(s2)=%ld\n", s2, strlen(s2)); // 5
	printf("s2=%s, sizeof(s2)=%ld\n", s2, sizeof(s2));	 // 6 -- 实际大小

	printf("\ns3=%s, strlen(s3)=%ld\n", s3, strlen(s3)); // 5
	printf("s3=%s, sizeof(s3)=%ld\n", s3, sizeof(s3));	 // 6 -- 实际大小

	printf("\ns4=%s, strlen(s4)=%ld\n", s4, strlen(s4)); // 10? 没有结束符....
	printf("s4=%s, sizeof(s4)=%ld\n", s4, sizeof(s4));	 // 5 -- 实际大小

	return 0;
}
