/**
 * @date 2023-07-19
 *
 * %p参考：
 *      https://www.coder.work/article/2748846
 *      https://blog.csdn.net/Young__Fan/article/details/90609247
 *
 * %02x:
 *      https://blog.csdn.net/qq_41483419/article/details/129791610
 *
 *
 *
 * 格式说明:
 *      %c  : char
 *      %d  : int
 *      %ld : long int
 *      %lu : long unsigned int

 *      %lld : long long
 *      %hd  : 短整型
 *      %f   : float
 *      %.2f : 保留小数点后两位
 *      %lf  : double
 *      %u   : 无符号数
 *      %x   : 16进制输出int 或者long int 或者short int
 *      %#x  : 16进制地址； (unsigned int)(long); 就是在16进制前面加上0x
 *      %o   : 八进制输出
 *      %s   : char *
 *
 *      #	 : 对c,s,d,u无影响；
 *             对o，在输出时加前缀o；
 *             对x，在输出时加前缀0x；
 *             对e,g,f 类当结果有小数时才给出小数点。
 *      %02x : 16进制输出，宽度至少是2，不足的用0补齐
 *             如： 0x3 --> 03, 0x13-->13
 *
 *      %p   : 输出16进制地址；有多少位打印多少位。32位编译器的指针变量为4个字节(32位)，64位编译器的指针变量为8个字节(64位)
 *
 *  打印颜色：
 *      #define END "\033[m"
 *      #define YELLOW "\033[1;33m"
 *      #define GREEN "\033[0;32;32m"
 *      #define LIGHT_RED "\033[1;31m"
 *      #define LIGHT_GREEN "\033[1;32m"
 *      #define LIGHT_CYAN "\033[1;36m"
 *      #define LIGHT_PURPLE "\033[1;35m"
 *
 *
 */
#include <stdio.h>

#define END "\033[m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32;32m"
#define LIGHT_RED "\033[1;31m"
#define LIGHT_GREEN "\033[1;32m"
#define LIGHT_CYAN "\033[1;36m"
#define LIGHT_PURPLE "\033[1;35m"

int main()
{
    printf("------------1.打印int--------------\n");
    int i = 0x17;

    printf("%%x   : %x\n", i);   // 17
    printf("%%01x : %01x\n", i); // 17
    printf("%%02x : %02x\n", i); // 17
    printf("%%03x : %03x\n", i); // 017
    printf("%%04x : %04x\n", i); // 0017
    printf("%%#x  : %#x\n", i);  // 0x17

    printf("\n------------2.打印 小数--------------\n");
    float f = 3.1415926;
    printf("%%.2f: %.2f\n", f);

    printf("\n------------3.打印 char *--------------\n");
    char *var = "hello";
    printf("%%s  : %s\n", var);

    printf("\n------------4.打印 地址--------------\n");
    int *p = &i;
    printf("%%x  : %x\n", p);  // 28816d24
    printf("%%#x : %#x\n", p); // 0x28816d24
    printf("%%p  : %p\n", p);  // 0x7ffe28816d24

    printf("\n------------5.打印 颜色--------------\n");
    printf(GREEN "green\n" END); // 打印颜色要用linux terminal

    return 0;
}