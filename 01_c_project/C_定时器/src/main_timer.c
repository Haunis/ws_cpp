/*
 * 	需要链接librt.a库
 *
 *  Eclipse配置动态链接库：
 *	本project→c/c++build→settings→GCC C++ Linker→Libraries→上方添加"rt"
 * 
 *  gcc -o main main_timer.c -lrt
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "tools.h"
#include "unistd.h"

#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)

//#define CLOCKID CLOCK_REALTIME
#define CLOCKID CLOCK_MONOTONIC

int count = 0;
////////////////////////派驻新线程的方式//////////////////////////////////////////////////////
timer_t timerid;
void init_thread_timer();
void set_time();

void execute_thread_timer();
void timer_thread(union sigval v)
{
//	printf("timer_thread pid: %d \n", getpid()); //pid和主线程相同,tid不同
//	printf("timer_thread tid :%d\n", gettid());
	printf("timer_thread function! %d\n", v.sival_int);
	count += 1;
	printf("count: %d\n", count);
	if (count >= 3)
	{
		count = 0;
		clearTimer();

//		usleep(2000 * 1000); //2000毫秒
//		printf("sleep\n");
//		deleteTimer();
		clearTimer();

		usleep(2000 * 1000); //2000毫秒
//		execute_thread_timer();
		set_time();
	}
}

void clearTimer()
{
	struct itimerspec timeout;
	timeout.it_value.tv_sec = 0;
	timeout.it_value.tv_nsec = 0; //NOTE: it's in nano seconds
	timeout.it_interval.tv_sec = 0;
	timeout.it_interval.tv_nsec = 0;

	if (-1 == timer_settime(timerid, 0, &timeout, NULL))
	{
		printf("[%d@%s] timer_settime error", __LINE__, __FUNCTION__);
	}
}
void deleteTimer()
{
	if (-1 == timer_delete(timerid))
	{
		printf("[%d@%s] timer_delete error", __LINE__, __FUNCTION__);
	}
}

///////////////////////信号的方式//////////////////////////////////////////////////////////////////////
void execute_signal_timer();
void sig_handler(int signo)
{
	printf("timer_signal function! %d\n", signo);
}

/////////////////////////main////////////////////////////////////////////////////////////////////////
int main()
{
	clearTimer();
//	deleteTimer();
	printf("main pid: %d \n", getpid());
	printf("main tid :%d\n", gettid());
//	usleep(2000 * 1000); //2000毫秒

//	init_thread_timer();
//	set_time();

//	execute_thread_timer(); //直接执行
//	execute_signal_timer();

	printf("主线程 \n");

	pause();
	return 0;
}
void set_time()
{
	struct itimerspec timeout;
	timeout.it_interval.tv_sec = 3;
	timeout.it_interval.tv_nsec = 50 * 1000000L;
	timeout.it_value.tv_sec = 0;
	timeout.it_value.tv_nsec = 1;

	if (-1 == timer_settime(timerid, 0, &timeout, NULL))
	{
		printf("[%d@%s] timer_settime error", __LINE__, __FUNCTION__);
	}
}
void init_thread_timer()
{
	struct sigevent evp;
	memset(&evp, 0, sizeof(struct sigevent));

	evp.sigev_value.sival_int = 30;    //标识定时器，回调函数可以获得
	evp.sigev_notify = SIGEV_THREAD;      //线程通知的方式，派驻新线程
	evp.sigev_notify_function = timer_thread; //回调函数
	if (-1 == timer_create(CLOCKID, &evp, &timerid))
	{
		printf("[%d@%s] timer_settime error", __LINE__, __FUNCTION__);
	}
}
void execute_thread_timer()
{
	//  int timer_create(clockid_t clockid, struct sigevent *evp, timer_t *timerid);
	// clockid--值：CLOCK_REALTIME,CLOCK_MONOTONIC,CLOCK_PROCESS_CPUTIME_ID,CLOCK_THREAD_CPUTIME_ID
	// evp--存放环境值的地址,结构成员说明了定时器到期的通知方式和处理方式等
	// timerid--定时器标识符
//	timer_t timerid;
	struct sigevent evp;
	memset(&evp, 0, sizeof(struct sigevent));	//清零初始化

	evp.sigev_value.sival_int = 30;		//也是标识定时器的，这和timerid有什么区别？回调函数可以获得
	evp.sigev_notify = SIGEV_THREAD;		//线程通知的方式，派驻新线程
	evp.sigev_notify_function = timer_thread;	//线程函数地址

	if (timer_create(CLOCKID, &evp, &timerid) == -1)
	{
		perror("fail to timer_create");
		exit(-1);
	}

	// XXX int timer_settime(timer_t timerid, int flags, const struct itimerspec *new_value,struct itimerspec *old_value);
	// timerid--定时器标识
	// flags--0表示相对时间，1表示绝对时间，通常使用相对时间
	// new_value--定时器的新初始值和间隔，如下面的it
	// old_value--取值通常为0，即第四个参数常为NULL,若不为NULL，则返回定时器的前一个值

	//第一次间隔it.it_value这么长,以后每次都是it.it_interval这么长,就是说it.it_value变0的时候会装载it.it_interval的值
	//it.it_interval可以理解为周期
	struct itimerspec it;
	it.it_interval.tv_sec = 1;	//间隔秒;it_interval可以不设定
	it.it_interval.tv_nsec = 50 * 1000000L;	//间隔纳秒;换算后成毫秒;不成超过1000*1000000L
	it.it_value.tv_sec = 0;	//多长时间后开始计时。value必须要设置
	it.it_value.tv_nsec = 1;

	if (timer_settime(timerid, 0, &it, NULL) == -1)
	{
		perror("fail to timer_settime");
		printf("failed \n");
		exit(-1);
	}

//	pause();
}

void execute_signal_timer()
{
	// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	// signum--指定的信号编号，可以指定SIGKILL和SIGSTOP以外的所有信号编号
	// act结构体--设置信号编号为signum的处理方式
	// oldact结构体--保存上次的处理方式
	//
	// struct sigaction
	// {
	// void (*sa_handler)(int);			//信号响应函数地址
	// void (*sa_sigaction)(int, siginfo_t *, void *);   //但sa_flags为SA——SIGINFO时才使用
	// sigset_t sa_mask;         //说明一个信号集在调用捕捉函数之前，会加入进程的屏蔽中，当捕捉函数返回时，还原
	// int sa_flags;
	// void (*sa_restorer)(void);	//未用
	// };
	//
	timer_t timerid;
	struct sigevent evp;

	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = sig_handler;
	act.sa_flags = 0;

	//  int sigaddset(sigset_t *set, int signum);  //将signum指定的信号加入set信号集
	//  int sigemptyset(sigset_t *set);			//初始化信号集

	sigemptyset(&act.sa_mask);

	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		perror("fail to sigaction");
		exit(-1);
	}

	memset(&evp, 0, sizeof(struct sigevent));
	evp.sigev_signo = SIGUSR1;
	evp.sigev_notify = SIGEV_SIGNAL;
	if (timer_create(CLOCK_REALTIME, &evp, &timerid) == -1)
	{
		perror("fail to timer_create");
		exit(-1);
	}

	struct itimerspec it;
	it.it_interval.tv_sec = 2;
	it.it_interval.tv_nsec = 0;
	it.it_value.tv_sec = 1;
	it.it_value.tv_nsec = 0;
	if (timer_settime(timerid, 0, &it, 0) == -1)
	{
		perror("fail to timer_settime");
		exit(-1);
	}
//	pause();
}

