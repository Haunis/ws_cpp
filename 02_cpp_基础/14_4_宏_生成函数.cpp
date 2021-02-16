/**
 * 参考/frameworks/native/include/binder/IInterface.h
 *
 * 宏其实就是字符展开替代,可以在宏里定义函数形式
 * 在全局或者类内部调用该宏,就可以真正定义函数
 */

#include <iostream>
#include <stdio.h>
using namespace std;

//调用宏后可生成funx()和funxx(两个函数)
#define FUN_MCRO(x,y) 										\
	const int fun##x()										\
	{printf("fun"#x",called...");cout<<y<<endl;return -1;}	\
	const int fun##x##x()									\
	{printf("fun"#x#x",called\n");return -1;}				\


FUN_MCRO(1, 1); //定义函数fun1()和fun11()
FUN_MCRO(2, 2); //定义函数fun2()和fun22()
//FUN_MCRO("a", "a"); //error 第一个参数要参与拼接,所以不能是"a"
FUN_MCRO(a, "a"); //定义函数funa()和funa()



//相当于调用funx(),funxx()
#define TEMP_MCRO(x,y) 				\
	fun##x(x,y);					\
	{printf("TEMP_MCRO\n");} 		\
	fun##x##x(x,y)					\
	
int main()
{
	fun1();
	fun11();

	fun2();
	fun22();

	funa();
	funaa();
	return 0;
}
