/*
 *匿名函数:
 *    https://www.cnblogs.com/yaya12138/p/11815475.html
 * 
 *    [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {
 *        // 函数体  
 *    }
 *
 *
 *std::function< int(int)> Functional;
 *https://blog.csdn.net/wangshubo1989/article/details/49134235
 *  
 */

#include <stdio.h>
#include <iostream>
#include <functional> //std::function

using namespace std;
int func(std::function<int(int, int)> f)
{
    return f(3, 4);
}

int main(int argc, char *argv[])
{
    auto p = [](int a, int b) -> int { return a + b; };

    int ret = p(3, 4);
    printf("ret = %d\n", ret);

    ret = func(p);
    printf("ret = %d\n", ret);
    return 0;
}
