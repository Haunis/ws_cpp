/**
 * 秒级时间戳：
 *      https://www.runoob.com/cplusplus/cpp-date-time.html
 * 
 * 毫秒级时间戳：
 *      https://blog.csdn.net/liyunlong41/article/details/76933575 
 * 
 */
#include <iostream>
#include <stdio.h>
#include <ctime>      //time
#include <sys/time.h> //timeval

using namespace std;

int64_t getMilliSecond() //毫秒
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
int64_t getMicroSecond() //微妙
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 * 1000 + tv.tv_usec;
}

int main(int argc, char *argv[])
{
    printf("----------------1.秒级时间戳---------------------\n");
    time_t now = time(0);   //long int; 返回 1970 年 1 月 1 日以来经过的秒数
    char *dt = ctime(&now); // 把 now 转换为字符串形式
    cout << "本地日期和时间：" << dt << endl;

    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);//格林威治时间
    dt = asctime(gmtm); //将返回字符串
    cout << "UTC 日期和时间：" << dt << endl;

    printf("year = %d\n", gmtm->tm_year); //注意时间是从1900年开始，加上次1900才是当前年份
    printf("mon = %d\n", gmtm->tm_mon);   //注意从0开始，+1
    printf("day = %d\n", gmtm->tm_mday);
    printf("hour = %d\n", gmtm->tm_hour);
    printf("min = %d\n", gmtm->tm_min);
    printf("sec = %d\n", gmtm->tm_sec);

    printf("\n*****转换为本地时间*****\n");
    tm *local_tm = localtime(&now);//本地时间
    printf("year = %d\n", local_tm->tm_year);
    printf("mon = %d\n", local_tm->tm_mon);
    printf("day = %d\n", local_tm->tm_mday);
    printf("hour = %d\n", local_tm->tm_hour);
    printf("min = %d\n", local_tm->tm_min);
    printf("sec = %d\n", local_tm->tm_sec);

    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", local_tm);
    printf("%s\n", tmp);

    printf("\n----------------2.毫秒级时间戳---------------------\n");
    int64_t now2 = getMilliSecond();//ms
    now2 = now2/1000;//s
    tm *local_tm2 = localtime(&now2);//本地时间
    char tmp2[64];
    strftime(tmp2, sizeof(tmp2), "%Y-%m-%d %H:%M:%S", local_tm2);
    printf("%s\n", tmp2);

    return 0;
}