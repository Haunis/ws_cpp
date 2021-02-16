#include<stdio.h>

extern "C"
{	
#include"add.h" //告诉main.o找的函数名是c语言的形式add,不是cpp形式的_Z3addii
}
// #include "add.h"

int main(int arg,char*argv[]){
	int ret = add(3,4);
	printf("main ret=%d\n",ret);
	return 0;
}
