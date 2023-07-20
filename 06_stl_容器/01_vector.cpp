/**
 *	https://blog.csdn.net/qq_40803710/article/details/80638386
 *	https://www.cnblogs.com/love-yh/p/7410666.html
 *
 *
 *	1.原理
 * 		vector底层数据结构是数组
 * 		扩容：	空间不足时，申请一个更大的数组(1.5或者2倍)，并将原数组内容拷贝至新数组
 * 		插入：	找到插入位置，将插入位置和后面的元素整体向后移动一位，空出来的位置放入新元素
 * 		删除：	将要删除的元素后面的所有元素整体向前移动一位
 *
 * 		size:	当前容器内有多少个元素
 * 		capactity:  指容器在必须分配新存储空间之前可以存储的元素总数，capacity总是大于或等于size的。
 *
 *	2.初始化:
 * 		vector<T> v1;                    //v1为空，执行默认初始化
 *		vector<T> v2(v1);                //v2中包含v1所有元素的副本
 *		vector<T> v2=v1;                //等价于v2(v1)
 *		vector<T> v3(n,val);            //v3中包含n个重复元素，每个元素的值都是val
 *		vector<T> v4(n);                //v4包含n个重复执行了值初始化的对象
 *		vector<T> v5{a,b,c...};         //包含初始化元素个数，每个元素被对应的赋予相应的值
 *		vector<T> v5={a,b,c...};        //等价v5{a,b,c...}
 *
 * 	3.vector常用方法:
 * 		front():返回第一个元素的引用
 * 		back():返回最后一个元素的引用
 * 		insert(index,value): 指定位置插入元素
 * 		erase(index):删除指定位置元素
 * 		size():返回容器内元素个数
 * 		capacity(): 容器大小
 * 		clear():清除所有元素，但仍然占着内存空间
 * 		reserve(n): 扩容； 已有容量小于n则扩容，大于n无动作
 * 		resize(n):	更改容器内元素个数，已有个数小于n则增加元素，新增加的用0填充；已有个数大于n则删除多余的
 *
 * 	4.查找某个元素是否存在:
 * 		https://blog.csdn.net/guotianqing/article/details/105832070
 * 		std::vector<int>::iterator it = std::find(v.begin(),v.end(),num)
 *
 * 	5.查找某个元素位置:
 * 		https://blog.csdn.net/loveC__/article/details/88647624
 * 		std::vector<int>::iterator it = std::find(v.begin(),v.end(),num)
 * 		if(it!=v.end()) int index = std::distance(nums.begin(), it);
 *
 *  6.push_back()和emplace_back()区别：
 * 		http://c.biancheng.net/view/6826.html
 * 		push_back():首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）
 * 		emplace_back(): 则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程;效率更高
 *
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm> //std::find()
#include <typeinfo>
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
	// vector<int> nums;//ok
	// vector<int> nums(3);//ok; 初始化三个元素，三个元素均为0
	// vector<int> nums(3,-1);//ok; 初始化三个元素，三个元素均为-1
	// vector<int> nums(vector<int>);//ok
	vector<int> nums = {1, 2, 3};

	printVec(nums);

	vector<int> v2(nums);
	printVec(v2);

	printf("---------------1.获取某个元素-------------------\n");

	int value = nums[0];
	printf("nums[0]=%d\n", nums[0]);

	printf("\n---------------2.更改-------------------\n");
	nums[0] = 18; // 可以赋值成功
	// nums[3] = 19;//赋值失败，只能对已有索引赋值
	printVec(nums);

	printf("\n---------------3.push_back:尾部插入元素-------------------\n");
	nums.push_back(4);	   // 向尾部添加
	nums.emplace_back(44); // 也是向尾部添加元素,c++11新添加的方法
	printVec(nums);

	printf("\n---------------4.insert:指定位置插入元素-------------------\n");
	printf("nums.begin()类型 --> %s\n", typeid(nums.begin()).name()); // N9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEE
	nums.insert(nums.begin() + 2, 222);								  // 在第index=2位置插入
	printVec(nums);

	printf("\n---------------5.pop_back:尾部弹出一个元素-------------------\n");

	nums.pop_back(); // 无返回值; 最后一个元素会被删除
	printVec(nums);

	printf("\n---------------6.查找元素-------------------\n");
	std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), 222);
	if (it == nums.end())
	{
		printf("222 无该元素\n");
	}
	else
	{
		int index = std::distance(nums.begin(), it);
		printf("222 元素索引:%d\n", index);
	}

	printf("\n---------------7.erase:删除指定位置元素-------------------\n");
	printVec(nums);
	printf("删除之后\n");
	nums.erase(nums.begin() + 1); // 删除第二个元素
	printVec(nums);

	printf("\n---------------8.front:返回第一个元素引用-------------------\n");
	// int front = nums.front();//ok;但不是常规用法
	int &front = nums.front(); // 返回第一个元素的引用;改变front的值会更改nums中的值
	printf("front类型 --> %s\n", typeid(front).name());
	front = front * 2;
	printVec(nums);

	int size = nums.size();
	nums.clear();

	printf("\n---------------9.assign:赋值-------------------\n");
	nums.push_back(1000);
	cout << "assign前: " << endl;
	printVec(nums);

	vector<int> temp = {11, 22, 33};
	nums.assign(temp.begin(), temp.end()); // 将temp所有元素全部赋值给intVec
	cout << "\nassign后: " << endl;
	printVec(nums);

	printf("\n---------------9.遍历-------------------\n");
	// for(int item: nums){
	for (auto item : nums)
	{
		cout << item << " ";
	}
	cout << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	printf("\n---------------10.排序-------------------\n");
	cout << "排序前" << endl;
	nums = {8, 9, 4, 1, 12, 7, 3};
	printVec(nums);

	sort(nums.begin(), nums.end());

	cout << "排序后" << endl;
	printVec(nums);

	printf("\n---------------11.扩容:reserve-------------------\n");
	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 7,7

	// nums.reserve(3);// 参数小于capacity，无操作
	nums.reserve(nums.capacity() + 20); // 参数大于capacity，扩容

	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 7,27

	printf("\n---------------12.更改容器内元素数量： resize-------------------\n");
	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 7,27

	printVec(nums);
	// nums.resize(nums.size() - 2); //减少2个元素
	nums.resize(nums.size() + 2); // 增加2个元素，新元素用0填充，若元素个数超出capacity则capacity自动扩容
	printVec(nums);

	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 9,27

	printf("\n---------------13.释放内存-------------------\n");
	for (int i = 0; i < 50; i++)
	{
		nums.push_back(i);
	}
	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 57, 112

	printf("\nclear ...\n");
	nums.clear();
	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 0, 112; vector内存未被清空.

	printf("\nswap ...\n");
	vector<int>().swap(nums);										  // 使用一个空vector进行内存交换, nums地址不变。
	printf("size=%ld, capacity=%ld\n", nums.size(), nums.capacity()); // 0,0

	return 0;
}
