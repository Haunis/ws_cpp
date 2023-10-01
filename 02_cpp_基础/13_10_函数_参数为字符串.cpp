#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc

void func(const char *msg)
{
    printf("func()1, msg=%s, len=%ld\n", msg, strlen(msg));
}

void func(char *msg)
{
    printf("func()2, msg=%s, len=%ld\n", msg, strlen(msg));
}

// 编译报错： redefinition,和void func(char *msg)重复定义
// void func(char msg[])
// {
//     printf("func()3, msg=%s, len=%ld\n", msg, strlen(msg));
// }

int main()
{

    printf("\n--------------1. 参数为const char* -------------\n");
    func("hello");

    printf("\n--------------2. 参数为 char* -------------\n");
    char *msg = (char *)malloc(sizeof(char) * 2); // 默认返回void*
    *(msg + 0) = 'a';
    *(msg + 1) = 'b';
    func(msg);

    free(msg);

    printf("\n--------------3. 参数为 char [] -------------\n");
    char msg2[] ="333";
    func("msg2"); //func( const char *) 

    return 0;
}