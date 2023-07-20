/**
 * @date 2023-07-20
 *
 * 	1.原理
 * 		内部基于红黑树实现；和java中TreeSet类似
 * 		set容器内无重复元素.
 *
 * 	2.常用方法
 * 		begin()--返回指向第一个元素的迭代器
 * 		end()--返回指向最后一个元素的迭代器
 *
 *		clear()--清除所有元素
 *		count()--返回某个值元素的个数
 *		empty()--如果集合为空，返回true
 *
 *		equal_range()--返回集合中与给定值相等的上下限的两个迭代器
 *		erase()--删除集合中的元素
 *		find()--返回一个指向被查找到元素的迭代器
 *		get_allocator()--返回集合的分配器
 *		insert()--在集合中插入元素
 *		lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
 *		key_comp()--返回一个用于元素间值比较的函数
 *		max_size()--返回集合能容纳的元素的最大限值
 *		rbegin()--返回指向集合中最后一个元素的反向迭代器
 *		rend()--返回指向集合中第一个元素的反向迭代器
 *		size()--集合中元素的数目
 *		swap()--交换两个集合变量
 *		upper_bound()--返回大于某个值元素的迭代器
 *		value_comp()--返回一个用于比较元素间的值的函数
 *
 *
 * 	删除操作：
 * 		删除一个节点后其他迭代器不会失效。
 * 		删除set的数据时，实际的操作是删除红黑树中的一个节点，然后相关指针做相关调整。
 * 		指向其他元素的迭代器还是指向原位置，并没有改变，所以删除一个节点后其他迭代器不会失效。
 * 		list和map也是同样的道理。
 * 		然而删除vector中的某个元素，vector中其他迭代器会失效，因为vector是基于数组的，
 * 		删除一个元素后，后面的元素会往前移动，所以指向后面元素的迭代器会失效。
 *
 * 	迭代器的实现：
 * 		迭代器是一个对象，vector的迭代器是封装了数组下标；list、map、set的迭代器是封装了元素节点的指针。
 *
 *
 *
 */

#include <iostream>
#include <set>
#include <stdio.h>
#include <algorithm> //std::find()
using namespace std;

class Node
{
public:
	int priority;
	string name;

public:
	Node(int priority)
	{
		this->priority = priority;
	}

public:
	// 重载“<”;按priority从小到大排列
	bool operator<(const Node mode) const
	{
		return this->priority < mode.priority;
	}
};

void printSet(set<Node> tmp_set)
{
	// for (set<Node>::iterator it = tmp_set.begin(); it != tmp_set.end(); it++)
	// {
	// 	cout << it->priority << " ";
	// }
	for (auto e : tmp_set)
	{
		cout << e.priority << " ";
	}
	cout << endl;
}

int main()
{
	set<Node>::iterator it;
	printf("\n---------------1.构造-------------------\n");
	// set<Node> my_set; //ok
	set<Node> my_set = {Node(7), Node(9), Node(2), Node(3)};
	printSet(my_set);

	printf("\n---------------2.插入元素: 5-------------------\n");
	my_set.insert(Node(5));
	my_set.insert(Node(5)); // set里元素不可重复，就算插入两次，set里也只有一个
	printSet(my_set);

	printf("\n---------------3.删除元素-------------------\n");
	printf("删除 5 \n");
	for (it = my_set.begin(); it != my_set.end(); it++)
	{
		if (it->priority == 5)
		{
			////////////////////////////////////
			// 这种方式也行
			// set<Node>::iterator tmp_it = it;//记录要删除的迭代器
			// it++; //循环的迭代器指向下一个
			// my_set.erase(tmp_it);
			////////////////////////////////////

			my_set.erase(it);
			break;
		}
	}
	printSet(my_set);

	printf("\n删除 3 \n");
	it = my_set.find(3);
	// it = std::find(my_set.begin(), my_set.end(), Node(7));//error; Node不是基本类型?
	my_set.erase(it);
	printSet(my_set);

	printf("\n---------------4.查找元素-------------------\n");
	it = my_set.find(9);
	if (it == my_set.end())
	{
		printf("无元素28\n");
	}
	else
	{
		int index = std::distance(my_set.begin(), it);
		printf("元素 9 索引:%d\n", index);
	}

	printf("\n---------------5.size -------------------\n");
	int size = my_set.size();
	bool isEmpty = my_set.empty();
	printf("size=%d, isEmpty=%c\n", size, isEmpty ? 'Y' : 'N');


	my_set.clear();
	printf("\nclear ...\n\n");

	size = my_set.size();
	isEmpty = my_set.empty();
	printf("size=%d, isEmpty=%c\n", size, isEmpty ? 'Y' : 'N');
	return 0;
}
