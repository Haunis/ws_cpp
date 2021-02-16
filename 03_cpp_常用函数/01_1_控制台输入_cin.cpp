/**
 * C: scanf ,gets,fgets
 * C++: cin ,getline
 * 
 * 参考:https://blog.csdn.net/qq_40725780/article/details/81032700
 * 
 * cin 接受字符串时,遇“空格”、“TAB”、“回车”就结束,取这些符号前面的
 * 	   就是只能读取一个单词
 * 	
 * 
 * 
 * 当同时使用cin>>,getline()时，需要注意的是，在cin>>输入流完成之后，getline()之前，需要通过
 * str="\n";
 * getline(cin,str);
 * 的方式将回车符作为输入流cin以清除缓存，如果不这样做的话，在控制台上就不会出现getline()的输入提示
 * 直接跳过，因为程序默认地将之前的变量作为输入流。
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	printf("\n---------------1.1 cin接受int----------------\n");

	int i;
	printf("cin 请输入一个整数:");
	cin >> i; //将输入的值保存在i里
	printf("i=%d\n", i);

	printf("\n---------------1.2 cin接受string或者char[]---------------\n");
	// string ss;//ok
	char ss[20];
	printf("cin 请输入一个字符串:");
	cin >> ss;
	cout << "ss=" << ss << endl;

	printf("\n---------------2.cin和cin.getline混用--------------\n");
	char temp[]="\n";
    cin.getline(temp,1);//清除缓存,否则会直接跳过cin.getline()

	printf("cin.getline 请输入一个字符串:");
	char arr[8];
	cin.getline(arr, 8);
	printf("arr=%s\n", arr);

	printf("\n---------------3.cin和getline混用--------------\n");
	char temp3[20];
	printf("cin 请输入一个字符串:");
	cin >> temp3;

	char temp31[]="\n";
    cin.getline(temp31,1);//清除缓存


	string temp32;
	printf("getline 请输入一个字符串:");
	getline(cin, temp32);
	printf("temp2=%s\n", temp32.data());
	return 0;
}
