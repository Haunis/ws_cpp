/**
 * 参考:
 * 		https://www.jianshu.com/p/fb9c7507d64e
 *
 * 宏中遇到#或##时就不会再展开宏中嵌套的宏了
 *
 * 1.# : 	字符串化操作，就是在首尾加上双引号
 * 2.##:	拼接符号; 如a##b,如果a,b出现在前面括号里,则将a,b变量的值替换,否则直接按字面替换
 *
 * 
 */
#include <iostream>
#include <stdio.h>
#include <stdarg.h>

void fun1()
{
	printf("fun1 called -->\n");
}
void funa()
{
	printf("funa called -->\n");
}
//-------------------------#--------------------------------
#define STRING(x) #x			   //字符串化操作，就是在首尾加上双引号;
#define STRING_STRING(x) STRING(x) //__FILE__传进来时,已经展开

//-------------------------##--------------------------------
#define FUN(x) fun##x()	//x传什么就是什么，如x=3,就是fun3()
#define PRINTF(n) printf("PRINTF -->token" #n "=%d\n", token##n) //n=9则展开为printf("PRINTF -->token9=%d\n",token9)
#define PRINTF2(n) printf("PRINTF2-->" #n "=%d\n", n##n) //a=9则展开为: printf("PRINTF2--> 9=%d\n",99)


#define SPLIT1 STRING(-)
#define SPLIT2 "-" //SPLIT1，SPLIT2相等

using namespace std;

int main()
{
	printf("系统宏 __FILE__=%s\n", __FILE__); //14_2_宏_宏拼接.cpp

	printf("\n---------------------1.#:字符串化----------------------\n");
	const char *p_char = STRING(hello);
	printf("p_char = %s\n", p_char); //hello

	char *p_char2 = STRING(__FILE__);  //遇到#或者##不会展开
	printf("p_char2 = %s\n", p_char2); //__FILE__;不展开

	char *pChar2 = STRING_STRING(__FILE__); //先展开__FILE__，再调用宏STRING_STRING,再调用STRING
	printf("pChar2 = %s\n", pChar2);		//ok,展开

	printf("SPLIT1 : %s\n", SPLIT1);
	if (SPLIT1 == SPLIT2)
	{
		printf("SPLIT1,SPLIT2: 相等");
	}
	else
	{
		printf("SPLIT1,SPLIT2: 不相等");
	}

	printf("\n---------------------2.## ：拼接----------------------\n");
	int a = 1;
	FUN(a); //funa()被调用,预编译直接字面替换

	int token9 = 100;
	PRINTF(9);
	PRINTF2(9);
	
	return 0;
}
