#include <unistd.h>
#include <stdio.h>
#include <ctime>      //time
#include <sys/time.h> //timeval
#include <iostream>

int64_t getMilliSecond() //毫秒
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

//code runner无法执行，使用c++ compile&run f6
int main(int argc, char *[])
{

    printf("usleep------>\n");
    usleep(1 * 1000 * 1000); //1s

    printf("sleep------>\n");
    int64_t start_t = getMilliSecond();
    sleep(1); //unistd.h头文件;单位是秒; 不能使用小数，小数的话就强转为0！！！！！
    printf("用时： %ld ms\n", getMilliSecond()-start_t);

    printf("quit\n");

    return 0;
}