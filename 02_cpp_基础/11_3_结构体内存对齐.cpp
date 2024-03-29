/**
 * @date 2023-07-21
 *
 *  参考：
 *      https://blog.csdn.net/m0_60274660/article/details/120796889
 *      https://blog.csdn.net/weixin_48896613/article/details/127371045
 *
 *  为何要内存对齐？
 *      为了提高cpu对内存的访问效率。
 *      32位系统cpu一次寻址4个字节，64位系统一次寻址8个字节。
 *      如果不对齐，对于64位系统来说，cpu读取的数据(8bytes)可能分布在两个存储地址，这样cpu就要读取两次，影响效率
 *
 *  对齐系数：每个特定平台上的编译器都有自己的默认“对齐系数”（也叫对齐模数）。
 *          32位系统，gcc中默认#pragma pack(4)，64位系统默认：#pragma pack(8)
 *      作用：即系统要求每一个数据最小占用多少内存
 *
 *
 *  对齐原则
 *      第一条规则：各成员的内存空间的首地址必须是对齐系数和数据类型本身大小较小者的整数倍，(即必须是有效对齐值的整数倍)
 *                如果是数组，需要根据数据类型大小，而不是总数组所占字节。
 *      第二条规则：对于结构体来说，在其各个数据都对齐之后，结构体本身也需要对齐，
 *                即结构体占用内存总大小应该为“对齐系数”和“最大数据长度”中较小值的整数倍。
 *
 */

#include <stdio.h>
#include "memory_dump.h" //查看内存

struct S1
{
    /*
         ———————————————————————————
        |    4 byte   |    4 byte   |
         ———————————————————————————
        | i j a       |             |  8 bytes; i、j、a共占用16位
         ———————————————————————————
        |             b             |  8 bytes; 64位系统是8byte对齐，所以b要在下一个8bytes位置存储
         ———————————————————————————

         共占用 8+8 = 16bytes
    */
    int i : 8; // i使用8位
    char j : 4;
    int a : 4;
    double b;
};
struct S2
{
    /*
         ———————————————————————————
        |    4 byte   |    4 byte   |
         ———————————————————————————
        | i j         |             |  8 bytes; i、j共占用12位
         ———————————————————————————
        |             b             |  8 bytes; 64位系统是8byte对齐，所以b要在下一个8bytes位置存储
         ———————————————————————————
        | a           |             |  8 bytes; a占4位
         ———————————————————————————

         共占用 8+8+ = 24bytes
    */
    int i : 8;
    char j : 4;
    double b;
    int a : 4;
};

struct S3
{
    /*
         ———————————————————————————
        |    4 byte   |    4 byte   |
         ———————————————————————————
        |             a             |  8 bytes;
         ———————————————————————————
        |             a             |  8 bytes;
         ———————————————————————————
        | a           |             |  8 bytes; char[18] 共占用24 bytes
         ———————————————————————————
        |             b             |  8 bytes; double单独占用8 bytes
         ———————————————————————————
        | c           |      d      |  8 bytes; char和int共用8 bytes
         ———————————————————————————
        |      e      |             |  8 bytes; int 占用8bytes
         ———————————————————————————

          共占用 6*8 = 48bytes
     */

    char a[18];
    double b;
    char c;
    int d;
    short e;
};

int g_a = 100;

int main()
{
    printf("S1 size: %ld\n", sizeof(S1)); // 16
    printf("S2 size: %ld\n", sizeof(S2)); // 24
    printf("S3 size: %ld\n", sizeof(S3)); // 48

    // debug后，监视窗口填入 memory_dump(sp, len, $rsp, $rbp)
    S1 s1 = {.i = 1, .j = 2, .a = 3, .b = 5};

    int len = (int)sizeof(s1);
    S1 *sp = &s1;

    printf("main..sp=%p\n", sp);
    

    sp->i = 10;

    printf("s1.i=%d, len=%d\n", sp->i, len);
    printf("&g_a=%p\n", &g_a);

    return 0;
}