/* 
 *	说到底宏就是编译时替换
 *
 *  参考：
 *		https://blog.csdn.net/u012707739/article/details/80170671
 * 		https://blog.csdn.net/weixin_40304387/article/details/80431739
 * 
 *1.带参数宏:
 *		一般定义形式： #define 宏名(形参表) 字符串，如：#define SQUARE(x) x*x
 					宏名和形参表不可以有空格 #define M (x) x*x这样会报错
 *		一般调用形式： 宏名(实参表),如SQUARE(3)

 *		在调用中要宏展开，并且用实参代替形参
 *			如：#define SQUARE(x) x*x, 调用i = SQUARE(3),展开后 i = 3*3
 *
 *	宏的参数是形参,实参可以传表达式
 *
 * 2.可变参数宏：
 * 		和可变参数函数一样"..."三个点表示可变参数,如：
 * 			#define PRINTF_VA(...) printf(__VA_ARGS__)
 *
 * 2.1 __VA_ARGS__ 宏的作用：
 *		用来表示可变参数的内容，就是将左边宏中 … 的内容原样抄写在右边__VA_ARGS__ 所在的位置
 *		如：#define PRINTF_VA(...) printf(__VA_ARGS__)
 *
 * 2.2参数起别名
 *		如果不使用__VA_ARGS__也可以给参数起名字，如：
 *			#define PRINTF_VA(format, args...) printf(format, ##args) 
 *
 * 2.3 ##作用:允许可变参数为空.
 *		  如果可变参数被忽略或者为空,“##”操作将使预处理器(preprocessor)去除掉它前面的那个逗号
 *		  可以不带"##",但如果可变参数为空,就会报错
 * 
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------固定参数宏--------------------------------
// #define SQUARE (x) x*x //error;宏名和形参直接不可有空格
#define SQUARE(x) x *x //宏定义
#define MAX(x, y) (x > y) ? x : y

// #define SAY(x) (x) //ok
// #define SAY(x)(x) //ok
#define SAY(x) x

//-------------------------可变参数宏--------------------------------
#define PRINTF_VA1(...) printf(__VA_ARGS__)	 //将左边宏中 … 的内容原样抄写在右边__VA_ARGS__ 所在的位置。
#define PRINTF_VA2(format, ...) printf(format, ##__VA_ARGS__) //c99的方式; ##--允许可变参数为空
#define PRINTF_VA3(format, args...) printf(format, ##args)	  //给参数起名字-arg；##--允许参数为空;
#define PRINTF_VA4(format, args...) printf(format, args)	  // 不允许参数为空
using namespace std;

int main()
{
	printf("\n---------------------1.固定参数宏----------------------\n");
	int x = 3;
	int ret = SQUARE(x); //3*3 = 9
	printf("QURARE(%d) = %d\n", x,ret);

	int a = 4, b = 8;
	int max = MAX(a, b);
	printf("MAX(%d, %d)=%d\n", a, b, max);

	int i = SAY(100);
	printf("i = %d\n", i);

	printf("\n---------------------2.可变参数宏----------------------\n");
	PRINTF_VA1("va1\n");
	PRINTF_VA2("va2\n");
	PRINTF_VA3("va3\n");
	// PRINTF_VA4("va4\n");//error,不允许参数为空
	PRINTF_VA4("va4:%d\n", 4);
	return 0;
}
