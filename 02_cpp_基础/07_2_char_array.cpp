/*
 * 1.char[]转string
 * 		char arr[] = "abc";
 * 		string str = arr;
 * 
 * 2.char []转int
 *		int x = atoi(arr)
 *	
 * 3.int转char[]
 * 		char ret[100];
 * 		sprintf(ret, "%d", 100);
 *
 */

#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

	printf("\n---------------1.char[] 转string---------------------\n");
	char arr[] = "abcd";
	string str = arr;
	printf("str = %s\n", str.data());			   //abcd
	cout << "sizeof(arr)=" << sizeof(arr) << endl; //5

	printf("\n---------------2.char[]转int----------------------------\n");
	char arr2[4] = "10";
	cout << atoi(arr2) << endl;
	cout << atol(arr2) << endl;
	cout << atof(arr2) << endl;

	printf("\n---------------3. int转char[]----------------------------\n");
	char ret[5];
	sprintf(ret, "%d", 52);
	printf("ret=%s\n", ret); //52
}
