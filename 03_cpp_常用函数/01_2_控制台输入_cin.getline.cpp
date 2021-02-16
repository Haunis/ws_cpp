/**
 * C: scanf ,gets,fgets
 * C++: cin ,getline
 * 
 * 参考:
 * 		https://blog.csdn.net/qq_40725780/article/details/81032700
 * 		http://c.biancheng.net/view/1350.html
 * 
 * cin.getline():
 * 		接收字符串,可以接收空格
 * 		实际上有三个参数:cin.getline(接收字符串的变量,接收字符个数,结束字符)
 *			当第三个参数省略时，系统默认为'\0'
 *			如果将例子中cin.getline()改为cin.getline(m,5,'a');则遇到a就会停止,只取a前面的字符
 * 		
 * cin.ignore(count,c):
 * 		参考：https://blog.csdn.net/wxbmelisky/article/details/48596881
 * 		忽略前面count个字符,或者遇到字符c,忽略c前面的字符(包括c)
 * 		如果默认不给参数的话，默认参数为cin.ignore(1, EOF)，即把EOF前的1个字符清掉,没有遇到EOF就清掉一个字符然后结束。
 *
 * 
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()	
{

	printf("------------------1.cin.getline()---------------\n");
	printf("请输入一个字符串:");
	// string arr;//error
	char arr[8];
	// cin.getline(arr, 8);	 //最多保留8-1=7个字符; 最后一个位置给null终止符留出空间
	cin.getline(arr, 5,'a');	 //最多保留8-1=7个字符; 最后一个位置给null终止符留出空间
	printf("arr=%s\n", arr); //输入啥就输出啥

	printf("\n------------------2.cin.ignore()---------------\n");
	printf("请输入一个字符串:");
	char arr2[8];
	cin.ignore(3, 'a');
	cin.getline(arr2, 8);	 //最多保留8-1=7个字符; 最后一个位置给null终止符留出空间
	printf("arr=%s\n", arr2); //输入啥就输出啥

	return 0;
}
