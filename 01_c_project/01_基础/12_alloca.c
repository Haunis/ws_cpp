/**
 * @date 2023-07-23
 *
 * 参考：
 *      https://blog.csdn.net/Motarookie/article/details/124707832
 *      https://zhuanlan.zhihu.com/p/449165315
 *
 *  栈的动态内存分配：
 *      alloca(): 在栈上申请动态内存，无需手动释放
 *
 *  适用场景：
 *      申请的内存空间只需要存在很短的时间，比如存储错误信息，之后打印到屏幕就结束其生命周期。
 *      这种情况如果每次都动态分配，几行代码之后手动释放。可以但没有必要
 *
 */
#include <stdio.h>
#include <malloc.h>

void fill_msg(char *msg)
{
    *(msg + 0) = 'h';
    *(msg + 1) = 'e';
    *(msg + 2) = 'l';
    *(msg + 3) = 'l';
    *(msg + 4) = 'o';
    *(msg + 5) = '\0'; // 结束符
}

void func()
{
    {
        // msg只存在很短的时间，可以在堆上申请之后再手动释放，但没必要这样做。
        // C
        char *msg = (char *)malloc(sizeof(char) * 10);
        free(msg);

        // // C++
        // char *msg = new char[10];
        // delete[] msg;

        fill_msg(msg);
        printf("msg = %s\n", msg);
    }

    {
        char *msg = (char *)alloca(sizeof(char) * 10);
        fill_msg(msg);
        printf("msg = %s\n", msg);
    }
}

int main()
{
    func();
    return 0;
}
