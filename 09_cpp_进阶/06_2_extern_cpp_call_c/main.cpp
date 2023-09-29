#include<stdio.h>

// #include "add.h" //error; 直接这样写，链接时会报错。

//ok; 告诉main.o找的函数名是c语言的形式add,不是cpp形式的_Z3addii
// extern "C"
// {	
// #include"add.h" 
// }


extern "C" int add(int x, int y); //ok; 相当于上面的写法 extern "C"{#include "add.h"}

int main(int arg,char*argv[]){
	int ret = add(3,4);
	printf("main ret=%d\n",ret);
	return 0;
}
