/*
 *  Created on: 2019年3月14日
 *
 *	std::thread实现
 *		32位的mingw不支持，要下载64位方可
 *		64位下载地址：http://mingw-w64.org/doku.php/download#mingw-builds
 *
 *		下载后要配置环境:Project->properties->C/C++ Build ->Environment->MINGW_HOME
 *		配置64位路径： 如C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0
 *
 *	linux实现：
 *		此project->properties->C/C++Build->Settings->Tool Settings->GCC C++ Linker->Libraries->add pthread
 *
 *	c++11标准线程库:
 *		c++11后有了标准的线程库:https://www.runoob.com/cplusplus/cpp-multithreading.html
 *		join和detatch的区别: https://blog.csdn.net/xibeichengf/article/details/71173543
 *
 *		join():调用该方法的线程会被阻塞;直到唤起的新线程执行完毕,调用处线程才会继续执行
 *		detach():调用该方法的线程不会被新线程阻塞
 *
 *	将线程构造出来后,会直接运行线程,join()和detach()方法只是设置线程和主线程的关系
 *
 *	如果子线程不设置join()或者detach()会有问题
 *		https://blog.csdn.net/github_20066005/article/details/79999530
 *
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdio.h>

using namespace std;
std::thread::id main_thread_id = std::this_thread::get_id();

void func1(int arg)
{
	printf("func1 arg=%d\n", arg);

	if (main_thread_id == std::this_thread::get_id())
		printf("\n*******func1 main thread, arg=%d\n", arg);
	else
		printf("\n*******func1 not main thread,arg=%d\n", arg);
}
void func2(int second)
{
	// std::this_thread::sleep_for(std::chrono::seconds(second));
	usleep(second * 1000 * 1000);
	printf("func2 : sleep %d seconds \n", second);
}

int main()
{
	printf("main_thread_id: %ld\n", main_thread_id);

	printf("\n-------------------1.t1线程启动-----------------------\n");
	std::thread t1(func1, 100);										  //直接定义并启动一个线程，线程和一个函数关联
	printf("hardware_concurrency : %d\n", t1.hardware_concurrency()); //可以并发执行多少个(不准确)
	printf("native_handle: %ld\n", t1.native_handle());				  //就是pthread_t,线程id

	t1.join(); //调用join()的线程(这儿是主线程)会被阻塞,直到t1执行完
	// t1.detach(); //调用线程的地方不会被阻塞

	printf("\n-------------------2.t2线程启动-----------------------\n");
	std::thread t2(func1, 200);
	t2.join(); //阻塞主线程
	// t2.detach();

	printf("\n-------------------3.启动5个线程-----------------------\n");
	std::thread threads[5]; // 默认构造线程

	printf("main 创建5个线程\n");
	for (int i = 0; i < 5; ++i)
		threads[i] = std::thread(func2, i); // move-assign threads

	for (auto &t : threads)
		// for (thread &t : threads)
		t.join(); //阻塞主线程

	printf("main exit\n");
	return 0;
}
