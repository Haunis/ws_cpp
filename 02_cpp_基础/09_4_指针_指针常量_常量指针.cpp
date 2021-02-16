/**
 * 3.指针常量和常量指针：
 * 		参考：https://blog.csdn.net/qq_36132127/article/details/81940015
 * 		https://wenku.baidu.com/view/756b54ca6529647d272852a5.html
 * 		指针常量：
 * 			指针类型的常量
 * 			常量意味着内存的值不可修改，指针常量说明该指针存储的值不可修改，而存储的值是个地址，也就是说此指针始终指向一个地址
 * 			不可以指向其他地址，定义时必须初始化;
 * 			指针指向的内存区域的值可以修改
 * 			<<<<<<固定指向一个地址，就是指针存的值不可改变；地址存储的内容可以改变>>>>>>
 * 			int a = 20;
 * 			int * const p = &a;
 * 		常量指针：
 * 			常量的指针；
 * 			虽说是"常量的指针"，但是此指针也可以指向变量，但指向该变量后，该变量就"升级为常量"值不可修改
 * 			指针可以指向其他地址
 * 			<<<<<<可以任意指定地址；地址存储的内容不可改变>>>>>>
 * 			应用场景：函数传参，在函数内部不修改指针指向的内容,如intstrcmp(const char *str1, const char *str2); 
 *
 * 			int a = 20;
 * 			int const *p =&a;或者 const int *p = &a;
 *
 * 		指向常量的指针常量：
 * 			指向常量，并且不可以指向其他地址
 * 			<<<<<<固定指向一个地址，并且地址存储的内容不可改变>>>>>>
 * 			const int a = 20;
 * 			const int *const p_const = &a;（最左侧用const修饰，修饰指针常量）
 *
 * 		不可以将常量地址赋给普通指针和指针常量，但可以将常量地址赋给常量指针和指向常量的指针常量
 *
 *
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a = 100;
	int b = 200;
	const int const_x = 300;
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("const_x = %d\n",const_x);
	printf("\n----------------1.1 指针常量_指向变量---------------------\n");
	
	//指针常量: 定义时必须初始化--本质是个常量，常量就必须初始化，因为编译时要进行常量重叠--见常量重叠demo
	//始终指向一个地址;地址存的内容可以改变
	int *const p_const = &a; 
	// p_const	= &b;//error,指针常量不可以再指向其他地址
	*p_const = 888; //可以改变指针存的地址的内容

	
	// int *const p_const2 = &const_x;//error,不能指向常量
									//因为指针常量指向的内存区域默认可以修改；

	// int *normal_p = &const_x; //error；也不可以将常量地址赋给普通指针
	
	printf("\n----------------1.2 指针常量之数组---------------------\n");
	char char_arr[]="abc"; //char_arr相当于指针常量，不可指向其他地方
	printf("char_arr=%s\n",char_arr);
	*char_arr='x';//ok
	printf("char_arr=%s\n",char_arr);

	// char_arr="ddd";//error,相当于指针常量不可以再指向其他地方
	


	printf("\n----------------2.1常量指针_指向变量和常量---------------------\n");
	//常量指针；可以不初始化；可以指向其他地址；地址存的内容不可改变
	const int *const_p = &a; //ok;可以指向其他地方，包括指向普通变量
	// *const_p = 18;//error;常量指针指向的内存区域不可修改，不管其指向的是常量还是变量
	const_p = &const_x;
	
	printf("*const_p = %d\n", *const_p);

	const int *const const_p2 = &const_x; //ok;指向常量的指针常量...指向常量，并且不可以指向其他地址

	

	printf("\n----------------2.2常量指针_字符串指针---------------------\n");

	char *char_s = "abc"; //这里实际是const char* char_s
	char_s = "ddd";
	printf("char_s=%s\n",char_s);

	// *char_s='x';//error，"abc"是常量，char_s这里是常量指针，其里面的内容不可修改
	return 0;
}
