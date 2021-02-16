/**
 * 具体内容可参考c++里的数组demo
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("-----------1.int 数组-------------\n");
	int int_arr[] = {0, 1, 2};
	// int_arr = {33,44,55};//int_arr相当于一个指针常量，不能再指向其他内存区域
	printf("int_arr size : %lu\n", sizeof(int_arr)); //3*4 = 12byte

	printf("int_arr= %#x\n", int_arr); 
	printf("&int_arr= %#x\n", &int_arr); //数组的地址其实就是第一个元素的地址，也称为首地址
	printf("i&int_arr[0]=%#x\n", &int_arr[0]); //这三个地址相等

	printf("int_arr[0] = %d\n", int_arr[0]); //0
	printf("int_arr[1] = %d\n", int_arr[1]); //1
	printf("int_arr[2] = %d\n", int_arr[2]); //2



	printf("\n---------2.将数组首地址赋值给一个指针------\n");
	int *p = int_arr;
	printf("*(p + 0) = %d\n", *(p + 0));//+1表示位移一个单位，一个单位是多少取决于指针的类型（char 1,int 4 等等）
	printf("*(p + 1) = %d\n", *(p + 1));
	printf("*(p + 2) = %d\n", *(p + 2));

	
	// int *p2 = {0, 1, 2};//error，虽然可以将数组首地址赋值给指针，但是数组不能这样初始化
	
	
	
	return 0;
}

