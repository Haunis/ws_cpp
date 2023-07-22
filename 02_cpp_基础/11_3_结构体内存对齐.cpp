/**
 * @date 2023-07-21
 *
 *  参考：
 *      https://blog.csdn.net/weixin_48896613/article/details/127371045
 *
 *
 */

#include <stdio.h>

struct S1
{
    int i : 8;
    char j : 4;
    int a : 4;
    double b;
};
struct S2
{
    /*
         ———————————————————————————————————————————————————————
        |    4 byte   |    4 byte   |    4 byte   |    4 byte   |
         ———————————————————————————————————————————————————————
         ———————————————————————————————————————————————————————
        |    int i    |    char j   |         double b          |  16 bytes
         ———————————————————————————————————————————————————————

    */
    int i : 8;
    char j : 4;
    double b;
    int a : 4;
};
struct S3
{
    int i;
    char j;
    double b;
    int a;
};

struct S4
{
    /*
         ———————————————————————————————————————————————————————
        |    4 byte   |    4 byte   |    4 byte   |    4 byte   |
         ———————————————————————————————————————————————————————
        |                       char[18]                        |  16 bytes
         ———————————————————————————————————————————————————————    
        |char[18]     |             |            double         |  16 bytes
         ———————————————————————————————————————————————————————
        |char c       |    int d    |shrot e                    |  16 bytes
         ———————————————————————————————————————————————————————
    */

    char a[18]; // 18 ->24
    double b;   // 8
    char c;     // 1 ->4
    int d;      // 4
    short e;    // 2 ->4
};

struct S5
{
    int i : 8;
    int j : 4;
    int a : 3;
    double b;
};
struct S6
{
    int i : 8;
    int j : 4;
    double b;
    int a : 3;
};
int main()
{
    printf("S1: %ld\n", sizeof(S1)); // 16
    printf("S2: %ld\n", sizeof(S2)); // 24
    printf("S3: %ld\n", sizeof(S3)); // 24
    printf("S4: %ld\n", sizeof(S4)); // 24
    printf("S5: %ld\n", sizeof(S5)); // 16
    printf("S6: %ld\n", sizeof(S6)); // 24

    S5 s5;
    s5.i = 1000;
    s5.j = 1002;
    s5.a = 1003;
    printf("i = %d\n", s5.i);
    printf("j = %d\n", s5.j);
    printf("a = %d\n", s5.a);
    return 0;
}