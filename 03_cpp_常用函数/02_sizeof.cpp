/*
 *  Created on: Mar 15, 2020
 *      Author: haunis
 * sizeof()不是函数。。。。
 * 和new ,delete一样，sizeof是c++定义的关键字
 */

#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int a = 10;
	int *p_int = &a;

	cout << "sizeof(int) : " << sizeof(int) << endl;			 //4
	cout << "sizeof(short) : " << sizeof(short) << endl;		 //2
	cout << "sizeof(short int) : " << sizeof(short int) << endl; //2
	cout << "sizeof(long) : " << sizeof(long) << endl;			 //4; 64系统是8
	cout << "sizeof(long long) : " << sizeof(long long) << endl; //8
	cout << "sizeof(double) : " << sizeof(double) << endl;		 //8
	cout << "sizeof(float) : " << sizeof(float) << endl;		 //4
	cout << "sizeof(char) : " << sizeof(char) << endl;			 //1
	cout << "sizeof(bool) : " << sizeof(bool) << endl;			 //1
	cout << "sizeof(void) : " << sizeof(void) << endl;			 //1
	cout << "sizeof(wchar_t) : " << sizeof(wchar_t) << endl;	//4
	cout << "sizeof(*p_int) : " << sizeof(p_int) << endl; //64位系统均是8;32系统4

	return 1;
}
