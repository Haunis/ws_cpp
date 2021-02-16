/**
 * 参考：https://blog.csdn.net/txgANG/article/details/78134625
 * 
 * deque：
 * 		双端队列
 *   	q.empty();
 *   	q.end();
 *   	q.erase(pos);//删除pos位置数据，传回下一个数据位置
 *   	q.erase(beg,end);//删除区间[beg,end]的数据，返回下一个数据的位置
 *   	q.front();
 *   	q.insert(pos,elem);//在pos位置插入一个elem数据，返回新数据位置
 *   	q.insert(pos,n,elem);//在pos位置插入n个elem
 *   	q.insert(pos,beg,end);//在pos位置插入在[beg,end]区间的数据
 *   	q.max_size();//返回容器中最大数据的数量
 *   	q.pop_back();//删除最后一个数据
 *   	q.pop_front();//删除头部数据；
 *   	q.push_back(elem);//在尾部加入一个元素
 *   	q.push_front(elem);//在头部加入一个元素
 */

#include <iostream>
#include <stdio.h>
#include <queue>
#include <deque>
#include <stdint.h>
#include <sys/time.h>
using namespace std;

int main()
{

	deque<int> my_deque;

	my_deque.push_front(1);
	my_deque.push_front(2);
	my_deque.push_front(3);

	int size = my_deque.size();
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", my_deque.front());
		my_deque.pop_front();
	}

	return 0;
}
