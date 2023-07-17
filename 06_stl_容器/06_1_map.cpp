/**
 * 
 * map基本用法：
 * 		https://blog.csdn.net/qq_39735236/article/details/82688904 
 * 
 * map和unorder_map区别：
 *		https://blog.csdn.net/BillCYJ/article/details/78985895
 *		map:底部实现是红黑树
 *		unorder_map:底部实现是哈希表
 * 
 */
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

void print_map(std::map<string, string> &mymap)
{
	std::string str_temp;
	for (std::map<std::string, std::string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		// printf("%s => %s\n", it->first.data(), it->second.data());
		// printf("typeid(it->first): %s\n", typeid(it->first).name());//NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
		str_temp = str_temp + it->first + " : " + it->second + "\t";
	}
	// cout << str_temp << endl;
	printf("%s\n", str_temp.data());
}

int main()
{
	std::map<std::string, std::string> mymap =
		{{"a", to_string(12)},
		 {"b", to_string(1.5)},
		 {"c", "bro_value"}};

	printf("-------------------1.插入/更新-------------------\n");
	mymap["d"] = "dd"; //赋值，有则更改，无则新加
	print_map(mymap);
	printf("----\n");
	mymap["d"] = "d2d2"; //可以更改
	print_map(mymap);

	cout << endl;

	mymap.insert(pair<string, string>("e", "eee")); //插入，有则不插入，无则插入
	print_map(mymap);
	printf("****\n");
	mymap.insert(pair<string, string>("e", "e2e2")); //无法更改，还是"test11"
	print_map(mymap);

	printf("\n-------------------2.1 删除数据:删除迭代器-------------------\n");
	//删除方式1：删除迭代器所指向的元素
	cout << "删除元素前" << endl;
	print_map(mymap);
	std::map<string, string>::iterator it = mymap.find("e");
	if (it != mymap.end())
	{
		mymap.erase(it);
	}
	else
	{
		printf("map中无该数据\n");
	}
	cout << "删除 e 后" << endl;
	print_map(mymap);

	printf("\n-------------------2.2 删除数据:删除key-------------------\n");
	//删除方式1：删除迭代器所指向的元素
	cout << "删除元素前" << endl;
	print_map(mymap);

	mymap.erase("d");

	cout << "删除 d 后" << endl;
	print_map(mymap);

	printf("\n-------------------2.3 删除数据:删除所有-------------------\n");
	cout << "清除前，size()= " << mymap.size() << endl;
	mymap.erase(mymap.begin(), mymap.end());
	cout << "清除后，size()= " << mymap.size() << endl;

	printf("\n-------------------3.查找数据-------------------\n");
	mymap["a"] = "aaa";
	it = mymap.find("a");
	if (it != mymap.end())
	{
		printf("找到了，key=%s, value=%s\n", it->first.data(), it->second.data());
	}
	else
	{
		printf("map中无该数据\n");
	}

	cout << "\n也可以用count" << endl;
	cout << "count(a): " << mymap.count("a") << endl;
	return 0;
}
