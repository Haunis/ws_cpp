
/**
 * 参考:
 * 		https://blog.csdn.net/lym940928/article/details/88368363
 * 		https://www.cnblogs.com/Jlord/p/11445878.html
 *inline函数：放在函数声明之前，要求该函数被调用时必须以代码的形式进行编译。
 *
 *对短小的函数有效，可以避免调用函数的一些常规操作时间，如参数堆栈的操作时间，所以编译结果的代码会更快一些
 *主要是减少栈内存消耗
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

inline int add(int i, int j = 2)
{
	return i + j;
}

int main()
{

	int ret = add(3, 5); //就是把 add(3,5)换成 i+j,避免频繁调用函数对栈内存的消耗
	cout << "ret = " << ret << endl;

	//	system("pause");
	return 0;
}
