/**
 * 三种队列介绍：
 * 		https://blog.csdn.net/txgANG/article/details/78134625
 * 
 * queue:
 * 		普通队列,先进先出
 * 	  	q.push();
 *      q.pop();
 *      q.front();
 *      q.back();//访问队尾元素
 *      q.size();
 *      q.empty();
 */

#include <iostream>
#include <stdio.h>
#include <queue>
#include <deque>
#include <stdint.h>
#include <sys/time.h>
using namespace std;
typedef unsigned int W_U32;

int main()
{
	queue<int> nor_queue;
	nor_queue.push(1); //向队列末端添加元素
	nor_queue.push(2);
	nor_queue.push(3);

	int size = nor_queue.size();
	// for (int i = 0; i < nor_queue.size(); i++) //这样写可以编译并运行，但是队列的大小在pop后会变，最终取出的不是所有元素
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", nor_queue.front());
		nor_queue.pop(); //不会返回元素的值
	}

	return 0;
}
