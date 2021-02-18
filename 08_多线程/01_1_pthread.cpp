/*
 *  Created on: 2019年3月13日
 *  
 *	windows下实现多线程方式有三：1.pthread	2.std 标准实现	3.windows api实现
 *	pthread实现：
 *	1.MinGW现在相应依赖库 ：mingw32-pthreads-32，dev、doc、lic三个都下
 *	2.添加动态链接库
 *		Project->Properties->C/C++Build->Settings->ToolSettings->MinGw C++Linker->Libraries
 *		添加Libraries (-l): pthread
 *
 *		注意是 pthread,不是lpthread,也不是-lpthread!!!
 *		(如果是64位的，现在啥问题都没。。。。)
 *
 *	std::thread实现
 *		32位的mingw不支持，要下载64位方可
 *		64位下载地址：http://mingw-w64.org/doku.php/download#mingw-builds
 *
 *		下载后要配置环境:Project->properties->C/C++ Build ->Environment->MINGW_HOME
 *		配置64位路径： 如C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0
 *
 * 
 *-------------------------------分割线----------------------------------------------
 *	编译：g++ -o main 01_1_pthread.cpp -lpthread
 *
 *	创建线程：
 * 		pthread_create(&tids[i], attr, func1, (void*) &i)；
 * 			tids:创建的线程id
 * 			attr:线程参数，线程参数用来设置可链接的，可分离的等等；可传NULL
 * 			func1:调用函数的地址
 * 			i: 函数参数,函数参数传入的时候必须强制转换为void* 类型，即无类型指针
 */

#include <iostream>
#include <pthread.h>
#include <unistd.h> //usleep
#include <stdio.h>
using namespace std;

class Student;
Student *instance = NULL;

class Student
{
private:
	int age;

public:
	Student(){};

public:
	static Student *getInstance()
	{
		printf("getInstance instance = %#x\n", instance);
		if (instance == NULL)
		{
			instance = new Student();
			printf("getInstance ...instance = %#x\n", instance);
		}
		return instance;
	}
	static void *study(void *arg)
	{
		pthread_detach(pthread_self()); //线程分离,线程执行完成后自动回收资源
		pthread_t *t = (pthread_t *)arg;
		printf("study *t=%d\n", *t);
		Student::getInstance()->studyMath();
		// instance->studyMath(); //两种方式都可以
		return NULL;
	}

	void studyMath()
	{
		printf("studyMath...\n");
	};
};

struct ThreadData
{
	int thread_id;
	char *msg;
};

void *func1(void *arg)
{
	//void型指针指向的值不可以直接被引用，必须转换成具体的类型,如char,int...
	printf("func1... 指针=%#x,参数=%d\n", arg, *((int *)arg));
	return NULL;
}
void *func2(void *arg)
{
	/*struct*/ ThreadData *struct_p; //可以不用struct关键字
	struct_p = (struct ThreadData *)arg;
	printf("func2... thread_id=%d,msg=%s\n", struct_p->thread_id, struct_p->msg);
	return NULL;
}

int main()
{
	printf("----------------------1.线程参数传递int-----------------------------\n");
	pthread_t tids[5]; //线程id
	int index[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; ++i)
	{
		printf("main 创建线程: %d\n", i);
		// int ret = pthread_create(&tids[i], NULL, func1, (void *)&i); //i的地址一直不变，可能导致取到地址里的值一样
		int ret = pthread_create(&tids[i], NULL, func1, (void *)&index[i]); //创建线程成功返回0
		if (ret != 0)
		{
			cout << "pthread_create error:error_code=" << ret << endl;
		}
	}

	usleep(1 * 1000 * 1000); //1秒；头文件unistd.h

	printf("\n----------------------2.线程参数传结构体-----------------------------\n");
	pthread_t tid = 100; //创建线程后,tid的值会改变
	ThreadData data = {tid, "this is struct msg"};

	printf("beforte tid = %d\n", tid);
	int ret = pthread_create(&tid, NULL, func2, (void *)&data); //成功则返回ret=0
	printf("after tid : %d\n", tid);							//创建线程后,t2的值会改变
	if (ret != 0)
	{
		cout << "pthread_create error:error_code=" << tid << endl;
	}
	pthread_join(tid, NULL); //主线程等待t2线程执行完再执行

	printf("\n----------------------3.线程回调类的方法----------------------------\n");
	instance = Student::getInstance();

	pthread_t tid3 = 1; //创建线程后,t2的值会改变
	int arg = 100;
	// pthread_create(&tid3, NULL, instance->studyMath, (void *)&arg);//error，必须是静态函数
	pthread_create(&tid3, NULL, Student::study, (void *)&arg);

	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	//如果main在它创建的线程之前结束，并通过pthread_exit()退出，那么其他线程将继续执行；否则，这些线程将在main()结束后停止
	pthread_exit(NULL);
	//	system("pause");
	return 0;
}
