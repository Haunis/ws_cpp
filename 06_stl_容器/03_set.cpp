#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

class Node
{
public:
	int priority;

public:
	Node(int priority)
	{
		this->priority = priority;
	}

public:
	//重载“<”;按priority从小到大排列
	bool operator<(const Node mode) const
	{
		return this->priority < mode.priority;
	}
};

int main()
{
	set<Node> mQueue;
	Node n1(1), n2(2), n3(3), n4(4);

	mQueue.insert(n2);
	mQueue.insert(n1);
	mQueue.insert(n3);
	mQueue.insert(n4);

	for (set<Node>::iterator it = mQueue.begin(); it != mQueue.end(); it++)
	{
		printf("priority:%d\n", it->priority);
	}

	// for (set<Node>::iterator &it : mQueue) //报错,不能使用
	// {
	// 	printf("type:%d, priority:%d\n", it->type, it->priority);
	// }
	bool isQueueEmpty = mQueue.empty();
	printf("isQueueEmpty = %d\n", isQueueEmpty);
	return 0;
}
