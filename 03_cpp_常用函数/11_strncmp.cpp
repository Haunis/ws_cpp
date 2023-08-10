/**
 * @date 2023-08-11
 *
 *  https://blog.csdn.net/m0_65601072/article/details/123993008
 *  逐位比较字符串ASCII差值。
 *  
 *  strcmp(s1, s2):
 *      s1 > s2 则结果大于0
 *      s1 < s2 则结果小于0
 *      s1 = s2 则结果等于0
 * 
 *  
 *  strcmp(s1, s2, n):指定比较前面n位
 *      
 * 
 */
#include <stdio.h>
#include <string.h> //strncmp

int main()
{
    const char *s1 = "abc";
    const char *s2 = "abx";
    const char *s3 = "abc";

    printf("\n---------------1. strcmp ----------------\n");
    printf("s1, s2  : %d\n", strcmp(s1, s2)); // -21
    printf("s1, s3  : %d\n", strcmp(s1, s3)); // 0

    printf("\n---------------2. strncmp ----------------\n");

    printf("s1, s2 ,2 : %d\n", strncmp(s1, s2, 2)); // 0 ; 前两位相等
    printf("s1, s2 ,3 : %d\n", strncmp(s1, s2, 3)); //-21
    printf("s1, s3 ,3 : %d\n", strncmp(s1, s3, 3)); // 0

    return 0;
}