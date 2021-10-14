/**
 * 
 * priority_queue:优先队列
 * 		https://www.cnblogs.com/Deribs4/p/5657746.html
 * 		priority_queue< type, container, function >：
 * 			type：数据类型
 *			container：实现优先队列的底层容器
 *			function：元素之间的比较方式；比较方式默认用operator<，
 *					所以如果把后面2个参数缺省的话，优先队列就是大顶堆（降序），队头元素最大

 *
 * 		如果有限队列里存储的指针,且让指针指向的实体按要求排序:
 * 			重载指针比较运算符,重新定义一个类
 * 			https://blog.csdn.net/AptX395/article/details/89968404
 *
 */

#include <iostream>
#include <stdio.h>
#include <queue>
#include <deque>
#include <stdint.h>
#include <sys/time.h>
using namespace std;
typedef unsigned int W_U32;

class Message
{
public:
	string m_strArgs; // messageArgs
	W_U32 m_when;

public:
	Message(const string &pData = "default_arg", W_U32 when = -1)
		: m_strArgs(pData), m_when(when)
	{
	}
};

class Compare_Node_Pointer
{
public:
	// Node::priority 大的优先
	bool operator()(Message *&a, Message *&b) const
	{
		return a->m_when > b->m_when;
	}
};

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
	//重载“<”;
	bool operator<(const Node node) const //返回true，说明this优先级小于node,
	{
		return this->priority < node.priority; //priority小的优先级低，小的排在后面，大顶堆
	}
};

int main()
{
	printf("----------------1. priority_queue 存基本数据类型int-----------------\n");
	// priority_queue<int, vector<int>, greater<int>> prio_queue; //小顶堆
	// priority_queue<int, vector<int>, less<int>> prio_queue; //大顶堆
	priority_queue<int> prio_queue; //默认大顶堆
	prio_queue.push(1);
	prio_queue.push(2);
	prio_queue.push(3);
	prio_queue.push(4);
	int size = prio_queue.size();
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", prio_queue.top());
		prio_queue.pop();
	}

	printf("----------------2. priority_queue 存引用-----------------\n");
	priority_queue<Node> prio_queue_ref;
	Node n1(1), n2(2), n3(3), n4(4);
	prio_queue_ref.push(n2);
	prio_queue_ref.push(n1);
	prio_queue_ref.push(n3);
	prio_queue_ref.push(n4);

	size = prio_queue_ref.size();
	for (int i = 0; i < size; i++)
	{
		Node n = prio_queue_ref.top();
		printf("n.priority: %d \n", n.priority);
		prio_queue_ref.pop();
	}

	printf("----------------3. priority_queue 存指针-----------------\n");
	priority_queue<Message *, std::vector<Message *>, Compare_Node_Pointer> prio_queue_p;

	Message *msgs = new Message[4];
	(msgs + 0)->m_when = 2;
	(msgs + 1)->m_when = 1;
	(msgs + 2)->m_when = 0;
	(msgs + 3)->m_when = 3;

	prio_queue_p.push(msgs + 0); //向队列插入数据
	prio_queue_p.push(msgs + 1); //向队列插入数据
	prio_queue_p.push(msgs + 2); //向队列插入数据
	prio_queue_p.push(msgs + 3); //向队列插入数据

	size = prio_queue_p.size();
	for (int i = 0; i < size; i++)
	{
		// Message *msg = prio_queue_p.top();
		printf(" m_when:%d \n", prio_queue_p.top()->m_when);
		prio_queue_p.pop();
		// delete msg; //error,不可以单独删除；要配对使用new-delete; new[] - delete[]
	}
	delete[] msgs;

	return 0;
}
