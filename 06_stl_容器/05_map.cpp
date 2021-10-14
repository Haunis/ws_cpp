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
		str_temp = str_temp + it->first + "=" + it->second + "\n";
	}
	// cout << str_temp << endl;
	printf("%s", str_temp.data());
}

int main()
{
	std::map<std::string, std::string> mymap =
		{{"a", to_string(12)},
		 {"b", to_string(1.5)},
		 {"c", "bro_value"}};

	printf("-------------------1.更改数据-------------------\n");
	mymap["d"]="test1"; //赋值，有则更改，无则新加
	mymap.insert(pair<string, string>("dd", "test11"));//插入，有则不插入，无则插入
	print_map(mymap);

	printf("----\n");
	mymap["d"]="test1_new";//可以更改
	mymap.insert(pair<string, string>("dd", "test11_new")); //无法更改，还是"test11"
	print_map(mymap);

	printf("-------------------2.删除数据-------------------\n");
	std::map<string, string>::iterator it;
	it=mymap.find("dd");
	if (it != mymap.end())
	{
		mymap.erase(it);
	}else{
		printf("map中无该数据\n");
	}

	print_map(mymap);

	printf("-------------------3.查找数据-------------------\n");
	it=mymap.find("a");
	if (it != mymap.end())
	{
		printf("%s,%s\n",it->first.data(),it->second.data());
	}else{
		printf("map中无该数据\n");
	}
	return 0;
}
