/**
 * C: scanf ,gets,fgets
 * C++: cin ,getline
 * 
 * getline(cin ,params):
 * 		可以读取一整行,包括空格,键盘键入啥就输出啥,不会像cin.getlin()少最后一个字符
 * 		第二个参数为接收输入数据的变量，不可为int型,可以是string
 * 
 * getline(cin,arg)和cin.getline(arg,count)区别:
 * 		cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数
 * 		getline()参数arg只能接收string,不能接收char arr[count]
 * 		cin.getlin()和getline()相反,只能接收char arr[count],不能接收string
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{

	// int i;
	// getline(cin, i);//error;getline() 不能接受int型参数

	// char ss[5];//error
	string ss;
	cout << "请输入一个字符串:";
	getline(cin, ss); //cin  和getline不能同时使用--比如适用了cin后再使用getline
	cout << "ss : " << ss << endl;

	return 0;
}
