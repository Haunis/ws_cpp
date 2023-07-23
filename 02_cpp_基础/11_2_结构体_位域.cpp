/**
 * @date 2023-07-23
 *
 * 参考:
 *      https://blog.csdn.net/m0_38106923/article/details/123298469
 *      https://blog.csdn.net/fengel_cs/article/details/120646897
 *
 * 位域的一般形式：
 *      struct 位域结构名
 *      {
 *          type name: width; //type:  只能为int, unsigned int, signed int
 *                            //width: 占几位，必须小于或等于指定位类型的宽度
 *      };
 *
 *
 */

#include <stdio.h>
struct S1
{

    /*

         ———————————————————————————————————————————————————————————————
        |    1 byte     |    1 byte     |     1 byte     |     1 byte   |
         ———————————————————————————————————————————————————————————————
        |j|j|j|j|i|i|i|i|i|i|i|i|a|a|a|a| | | | | | | | | | | | | | | | |
         ———————————————————————————————————————————————————————————————
        |                               b                               |
         ———————————————————————————————————————————————————————————————

        j、i、a分别占4、8、4共16位，小于4bytes，所以共用4bytes
        所以共 4bytes + 4bytes = 8bytes

    */

    char j : 4; // 占4位
    int i : 8;
    int a : 4;
    int b; // 4 bytes
} s1;

int main()
{

    printf("size = %ld\n", sizeof(S1)); // 8

    s1.j = 7;                    // 由于是4位有符号位，所以储存最大的数是0b111，即10进制的7
    printf("s1.j = %d\n", s1.j); // 7

    s1.j = 8;
    printf("s1.j = %d\n", s1.j); // -8; 溢出，超出最大范围

    return 0;
}