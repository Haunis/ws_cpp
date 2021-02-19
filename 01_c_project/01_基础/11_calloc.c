/**
 * 
 * void* calloc（unsigned int num，unsigned int size）:
 *      num:要申请多少个元素
 *      size:每个元素大小
 * 
 * malloc与calloc区别： 
 *      https://www.cnblogs.com/mfrbuaa/p/5383026.html
 *      1.语法上有区别，calloc函数有两个参数
 *      2.calloc会对申请的元素进行初始化，初始化为0
 *      malloc(sizeof(int) * 3): 直接申请多少个字节
 *      calloc(length, sizeof(int)):申请 length*sizeof(int)个字节
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void printArray(void *p, int eleType, int arrayLength)
{
    switch (eleType)
    {
    case sizeof(int):
    {
        int *intP = (int *)p; //在case下定义变量时，c语言这个地方要加花括号
        for (int i = 0; i < arrayLength; i++)
        {
            printf("*(intP+%d)=%d\n", i, *(intP + i));
        }
    }
    break;
    }
}

int main()
{
    int length = 4;
    int *p = (int *)calloc(length, sizeof(int)); //默认返回void*,要强转
    *(p + 0) = 0;
    *(p + 1) = 1;
    *(p + 2) = 2;
    *(p + 3) = 3;
    printArray(p, sizeof(int), length);

    free(p);
    printf("after free...\n");
    printArray(p, sizeof(int), length);
    return 0;
}