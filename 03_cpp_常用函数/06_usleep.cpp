#include <unistd.h>
#include <stdio.h>

//code runner无法执行，使用c++ compile&run f6
int main(int argc, char *[])
{

    printf("usleep------>\n");
    usleep(1 * 1000 * 1000); //1s

    printf("sleep------>\n");
    sleep(2); //unistd.h头文件;单位是秒
    printf("quit\n");

    return 0;
}