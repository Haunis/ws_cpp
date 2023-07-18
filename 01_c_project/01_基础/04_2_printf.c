/**
 * @date 2023-07-19
 *
 * %p参考：
 *      https://www.coder.work/article/2748846
 *      https://blog.csdn.net/Young__Fan/article/details/90609247
 * 
 * 
 * 格式说明
 * 	%c  - char
 *	%d  -  int
 *	%ld -long int
 *	%lu -long unsigned int

 *	%lld - long long
 *	%hd - 短整型
 *	%f -  float
 *	%lf - double
 *	%u - 无符号数
 *	%x - 十六进制输出int 或者long  int 或者short int
 *	%o -  八进制输出
 *	%s - 字符串

 *  %#x - 输出16进制地址； (unsigned int)(long)
 *  %p  - 输出16进制地址；有多少位打印多少位。32位编译器的指针变量为4个字节(32位)，64位编译器的指针变量为8个字节(64位)
 *
 */
#include <stdio.h>

int main(){
    printf("------------1.打印int 和地址--------------\n");
    int i = 10;

    printf("i = %x\n",i);//a
    printf("i = %#x\n",i);//0xa
    printf("i = %p\n",i);//0xa

    int* p = &i;
    printf("p = %x\n", p); // 723bef6c
    printf("p = %#x\n",p);//0x723bef6c
    printf("p = %p\n", p); // 0x7fff723bef6c

    printf("\n------------2.打印 char *--------------\n");
    char *var = "hello";
    printf("var = %s\n", var);

    return 0;
}