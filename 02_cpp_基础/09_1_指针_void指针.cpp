/**
 *1.void型指针：
 *		void型指针是特殊类型的指针，可以指向任意类型的数据，整数，浮点，字符串均可
 *		void型指针指向的值不可以直接被引用，因为它的长度是不固定的，必须转换成具体的类型,如char,in...
 *		应用场景：用来给函数传递通用参数
 *
 *
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;


//形参data会新创建一个指针，指针存储的内容和调用处指针存储的内容一致
void increase(void *data, int type)
{
	switch (type)
	{
	case sizeof(char):
		(*((char *)data))++; //将void型指针强转成char型指针，再将指针指向的值进行+1操作
		break;
	case sizeof(int):
		(*((int *)data))++;
		break;
	}
}

int main()
{
	char a = 'a';
	int i = 1;
	printf("before,a=%c,i=%d\n",a,i);

	increase(&a, sizeof(char));
	increase(&i, sizeof(i));

	printf("after,a=%c,i=%d\n", a, i);

	return 0;
}
