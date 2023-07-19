/**
 * @date 2023-07-18
 *
 * 参考：
 *      https://blog.csdn.net/qq_40737025/article/details/107004964
 *
 * 析构函数被调用时机：
 *      1. 栈区的对象，函数执行完就调用析构
 *      2. new 出来的对象，执行delete后才调用析构
 */

#include <stdio.h>
#include <iostream>
using namespace std;

class Bean
{
public:
    int num;

public:
    Bean(int num = -1) : num{num}
    {
        printf("Bean 构造 num=%d, this = %p\n", num, this);
    }
    ~Bean()
    {
        printf("Bean 析构.. this = %p\n", this);
    }
};

class Outer
{
public:
    Bean bean;
    int num;

public:
    Outer() : num{18}
    {
        printf("Outer 构造 num=%d, this = %p\n", num, this);
    }

    ~Outer()
    {
        printf("Outer 析构.. this = %p\n", this);
    }
};

int main()
{

    printf("\n----------------1. 栈区对象-------------------\n");
    {
        Bean bean(18);
    }
    printf("\n----------------2. new 对象-------------------\n");
    Bean *bp;
    {
        bp = new Bean(12);
    }
    printf("delete bp.....\n");
    delete bp; // 手动执行delete后才调用对象的析构

    printf("\n----------------3. 析构顺序： 先本对象，再成员对象-------------------\n");
    {
        Outer o;
        printf("\no.num=%d, &o = %p\n", o.num, &o);
        printf("o.bean.num=%d, &o.bean = %p\n\n", o.bean.num, &(o.bean));
    }

    printf("\n----------------code end-------------------\n");

    return 0;
}