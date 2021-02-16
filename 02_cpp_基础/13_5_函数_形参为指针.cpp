
/**
 *
 * 函数形参为指针：调用此函数时，会新建局部变量，亦即新指针；
 * 				新指针存储的地址和调用处指针存储的地址一致
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void func(int *i)
{
	//i为新指针，指针存储的地址就是调用处指针传入的地址
	printf("func --> &i = %#x\n", &i);
	printf("func --> i = %#x\n", i);
	printf("func --> *i = %d\n", *i);
	*i = 10;
}
void func2(char **pp)
{
	printf("func2 --> pp = %#x\n", pp); //pp是个二级指针,里面存储的是传入指针char_p的地址
	printf("func2 --> *pp = %s\n", *pp);//abc; 
	printf("func2 --> *pp = %#x\n", *pp);//字符串首地址;char_p存储的地址
	printf("func2 --> &pp = %#x\n", &pp);
	char *temp = "hello func2";
	*pp = temp; //char_p指向一块新的内存区域;  这样赋值貌似不安全,temp是局部变量
	printf("func2 --> *temp:%c\n", *temp);
	
}
void func3(int *&int_p) //就相当于操作调用处的指针
{
	//i为新指针，指针存储的地址就是调用处指针传入的地址
	printf("func3 --> &int_p = %#x\n", &int_p);
	printf("func3 --> int_p = %#x\n", int_p);
	printf("func3 --> *int_p = %d\n", *int_p);
	// *i = 10;
}

int main()
{
	int x = 1;
	int *p_x = &x;

	printf("x=%d, &x=%#x\n", x, &x);
	printf("p_x = %#x\n", p_x);
	printf("&p_x = %#x\n", &p_x);

	printf("-----------------1.参数为一级指针--------------------\n");
	func(p_x);
	printf("x = %d\n", x);

	printf("-----------------2.参数为二级指针--------------------\n");
	char *char_p = "abc";		  //实际是const char*类型
	printf("char_p=%s\n", char_p);//abc; 使用%s可以直接打印出指针指向的内容
	printf("char_p=%#x\n", char_p);	//字符a的地址,就是字符串首地址
	printf("&char_p=%#x\n", &char_p);//指针char_p的地址

	func2(&char_p);
	printf("after,func2 char_p=%s\n", char_p);
	printf("char_p=%#x\n", char_p);	//char_p存储的地址已经改变,指向了一块新内存区域
	


	printf("\n--------------3.函数参数为指针且是引用传递-----------\n");
	printf("&p_x = %#x\n", &p_x);
	printf("p_x = %#x\n", p_x);
	printf(" *p_x = %d\n", *p_x);
	func3(p_x);
	//	system("pause");
	return 0;
}
