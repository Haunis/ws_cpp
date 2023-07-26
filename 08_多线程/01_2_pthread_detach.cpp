/*
 *	编译：g++ -o main 01_2_pthread_detach.cpp -lpthread
 *
 *	线程的连接和分离：
 *		参考：
 *		http://www.runoob.com/cplusplus/cpp-multithreading.html
 *		https://blog.csdn.net/weibo1230123/article/details/81410241
 *
 *		线程只有设置可连接的（PTHREAD_CREATE_JOINABLE）才可以被连接
 *		线程设置可分离的（PTHREAD_CREATE_DETACHED）则不可被连接
 *
 *		一个线程如A仅允许一个线程如B使用pthread_join等待A结束。
 *		不能被多个线程等待,否则第一个收到信号的线程成功返回,其余调用pthread_join的线程返回错误码
 *		错误码:SRCH  No thread with the ID thread could be found.
 *
 *		一个可pthread_join的线程所占用的资源仅当有线程对其执行了pthread_join后才会释放
 *		因此为了防止内存泄漏，所有线程终止时，要么已经被设置为DETACHED状态,要么使用pthread_join来回收资源。
 *
 *		在线程设置为joinable后，可以调用pthread_detach()使之成为detached。
 *		但是相反的操作则不可以。还有，如果线程已经调用pthread_join()后，则再调用pthread_detach()则不会有任何效果。
 *
 *	线程终止：
 *		https://www.cnblogs.com/zhangxuan/p/6430034.html
 *		https://blog.csdn.net/zhou1021jian/article/details/71531699
 *
 *		线程正常终止的方法：
 *		1、return从线程函数返回。
 *		2、通过调用函数pthread_exit使线程退出
 *		3. 线程可以被同一进程中的其他线程取消。
 *
 *		主线程、子线程调用exit， pthread_exit，互相产生的影响。
 *		1、在主线程中，在main函数中return了或是调用了exit函数，则主线程退出，且整个进程也会终止
 *			此时进程中的所有线程也将终止。因此要避免main函数过早结束。
 *		2、在主线程中调用pthread_exit,   则仅仅是主线程结束，进程不会结束，进程内的其他线程也不
 *			会结束，直到所有线程结束，进程才会终止。
 *		3、在任何一个线程中调用exit函数都会导致进程结束。进程一旦结束，那么进程中的所有线程都将结束。
 *
 *	线程取消：
 *		一般情况下，线程在其主体函数退出的时候会自动终止，但同时也可以因为接收到另一个线程发来的终止（取消）请求而强制终止。
 *
 *		线程取消的方法是向目标线程发Cancel信号，但如何处理Cancel信号则由目标线程自己决定，或者忽略（当禁止取消时）、
 *		或者立即终止（当在取消点 或异步模式下）、或者继续运行至Cancelation-point（取消点，下面将描述）
 *		总之由不同的Cancelation状态决定。
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <errno.h>
using namespace std;

#define NUM_THREAD 5

void *func(void *arg)
{
	//线程分离,线程执行完成后自动回收资源；设置detach之后，其他线程不可join该线程
	// pthread_detach(pthread_self());

	long long_arg = *((int *)arg);	//转换成int*指针后再取值
	usleep(long_arg * 1000 * 1000); //第一个线程等1s,第二个2s...
	printf("func long_arg :%ld\n", long_arg);
	//	pthread_exit(NULL);
	*((int *)arg) = *((int *)arg) * 10; //里面存的值乘以10
	pthread_exit(arg);					//可以返回arg给所join该线程的线程
}

int main()
{
	int fun_arg[NUM_THREAD] = {1, 2, 3, 4, 5}; //创建线程时,传递给函数参数

	pthread_t thread_id[NUM_THREAD]; //创建线程后,thread_id存储的值会改变

	pthread_attr_t attr;
	pthread_attr_init(&attr);									 //初始化
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //设置线程是可连接的（joinable）

	for (int i = 0; i < NUM_THREAD; i++)
	{
		// int ret = pthread_create(&thread_id[i], NULL, func, (void *)&fun_arg[i]); //不设置线程参数attr
		int ret = pthread_create(&thread_id[i], &attr, func, (void *)&fun_arg[i]);
		if (ret != 0) //线程创建成功返回0
		{
			cout << "Error:unable to create thread : " << ret << endl;
			// exit(-1); //需要导入cstdlib
			exit(errno);
		}
	}

	printf("main thread continue...\n");

	//所等待的线程的返回值储存在该指针指向的位置。
	//该返回值可以是由pthread_exit给出的值,或者该线程被取消而返回PTHREAD_CANCELED
	void *status;

	//删除属性，并等待其他线程；
	//函数将对象属性初始化为其缺省值。分配一些存储空间，所以需要下面的函数删除初始化期间分配的存储空间。
	pthread_attr_destroy(&attr);
	for (int i = 0; i < NUM_THREAD; i++)
	{
		//等待线程threads[i]执行完，调用pthread_join()的线程(此处为主线程)再执行
		int ret = pthread_join(thread_id[i], &status);
		if (ret != 0)
		{
			cout << "Error:unable to join," << ret << endl;
			exit(-1);
		}
		printf("main join thread_id=%lu, *status=%d\n", thread_id[i], *((int *)status));
	}

	cout << "main: program exit" << endl;
	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	//如果main在它创建的线程之前结束，并通过pthread_exit()退出，那么其他线程将继续执行；否则，这些线程将在main()结束后停止
	pthread_exit(NULL); //主线程结束，子线程继续执行
	return 0;
}
