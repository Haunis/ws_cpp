/**
 * 参考：
 *      https://blog.csdn.net/z_muyangren/article/details/105398871
 *
 *  初始化互斥锁：
 *      pthread_mutex_t mtx;
 *      pthread_mutex_init(&mtx, NULL);//第二个参数为 NULL，互斥锁的属性会设置为默认属性
 * 
 *  阻塞调用：
 *      pthread_mutex_lock(&mtx);
 *  
 *  非阻塞调用：
 *      int err = pthread_mutex_trylock(&mtx);
 *      if(0 != err) {
 *          if(EBUSY == err) {
 *              //The mutex could not be acquired because it was already locked.
 *          }
 *      }
 *  超时调用：
 *      struct timespec abs_timeout;
 *      abs_timeout.tv_sec = time(NULL) + 1;
 *      abs_timeout.tv_nsec = 0;
 *      int err = pthread_mutex_timedlock(&mtx, &abs_timeout);
 *      if(0 != err) {
 *          if(ETIMEDOUT == err) {
 *              //The mutex could not be locked before the specified timeout expired.
 *          }
 *      }
 * 
 *  释放互斥锁：
 *      pthread_mutex_unlock(&mtx);
 *  
 *  销毁互斥锁：
 *      pthread_mutex_destroy(&mtx)
 *
 * 
 *  编译： g++ -o main 01_3_pthread_互斥锁.cpp -lpthread
 */

#include <pthread.h>
#include <stdio.h>
#include <assert.h>

int count = 0;
pthread_mutex_t mtx;

void *fun1(void *arg)
{
    for (int i = 0; i < 10000; i++)
    {
        pthread_mutex_lock(&mtx); //不可重入！！！
        count++;
        pthread_mutex_unlock(&mtx); //必须释放，否则下次循环无法获取！！！
    }
    return NULL;
}

int main()
{

    //初始化锁； 第二个参数为 NULL，互斥锁的属性会设置为默认属性
    pthread_mutex_init(&mtx, NULL);

    pthread_t tid1, tid2;
    int ret;

    // 创建第一个线程
    ret = pthread_create(&tid1, NULL, fun1, NULL); // 成功则返回ret=0
    assert(ret == 0);

    // 创建第二个线程
    ret = pthread_create(&tid2, NULL, fun1, NULL); // 成功则返回ret=0
    assert(ret == 0);

    pthread_join(tid1, NULL); // 主线程等待子线程执行完..
    pthread_join(tid2, NULL); // 主线程等待子线程执行完..
    printf("count = %d\n", count);

    pthread_mutex_destroy(&mtx);//销毁锁
    return 0;
}