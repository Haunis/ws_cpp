/**
 *	https://blog.csdn.net/qq_40803710/article/details/80638386 
 *	https://www.cnblogs.com/love-yh/p/7410666.html
 *
 *	初始化:
 * 		vector<T> v1;                    //v1为空，执行默认初始化
 *		vector<T> v2(v1);                //v2中包含v1所有元素的副本
 *		vector<T> v2=v1;                //等价于v2(v1)
 *		vector<T> v3(n,val);            //v3中包含n个重复元素，每个元素的值都是val
 *		vector<T> v4(n);                //v4包含n个重复执行了值初始化的对象
 *		vector<T> v5{a,b,c...};         //包含初始化元素个数，每个元素被对应的赋予相应的值
 *		vector<T> v5={a,b,c...};        //等价v5{a,b,c...}
 *
 * 	vector常用方法:
 * 		front():返回第一个元素的引用
 * 		back():返回最后一个元素的引用
 * 		insert(index,value): 指定位置插入元素
 * 		erase(index):删除指定位置元素
 * 		size():大小
 * 		clear():清除所有元素
 * 		
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

void printVec(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		printf("%d\t", vec[i]);
	}
	printf("\n");
}

int main()
{
	// vector<int> intVec;//ok
	vector<int> intVec = {1, 2, 3};
	printVec(intVec);

	printf("---------------1.获取某个元素-------------------\n");
	int value = intVec[0];
	printf("intVec[0]=%d\n", intVec[0]);

	printf("---------------2.push_back:尾部插入元素-------------------\n");
	intVec.push_back(4); //向尾部添加
	printVec(intVec);

	printf("---------------3.insert:指定位置插入元素-------------------\n");
	intVec.insert(intVec.begin() + 1, 222);
	printVec(intVec);

	printf("---------------4.erase:删除指定位置元素-------------------\n");
	intVec.erase(intVec.begin() + 1);
	printVec(intVec);

	printf("---------------5.front:返回第一个元素引用-------------------\n");
	// int front = intVec.front();//ok;但不是常规用法
	int &front = intVec.front(); //返回第一个元素的引用;改变front的值会更改intVec中的值
	front = front * 2;
	printVec(intVec);

	int size = intVec.size();
	intVec.clear();

	return 0;
}
