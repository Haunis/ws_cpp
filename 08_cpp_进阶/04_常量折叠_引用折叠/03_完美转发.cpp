/**
 * 参考：
 *      https://zhuanlan.zhihu.com/p/50816420
 * 
 * 完美转发：接受到的是左值则调用相应左值函数，接受到的是右值则调用相应右值函数
 * 
 * std::forward实现完美转发，其大致源码如下：
 *      template<typename T>
 *      T&& forward(T &param)
 *      {
 *	        return static_cast<T&&>(param);
 *      }
 *      分析可得：
 *          1.如果接受的T是左值引用，如int&，返回int& &&，最终还是左值引用类型
 *          2.如果接受的T是右值，如int,则T被推导为值类型，返回T&& 为int&&,是右值引用类型
 * 
 */

#include <stdio.h>
#include <typeinfo>
#include <iostream>
using namespace std;

template <class T>
void f(T &param)
{
    printf("f T&  \n");
}

template <class T>
void f(T &&param)
{
    printf("f T&&  \n");
}

template <class T>
void func(T &&param) //万能引用
{
    /*  
        T&& 必定是个引用类型
        1.如果T是int(右值), 那么T&& 就是 int &&；
        2.如果T为&&(右引用),那么T &&(&& &&) 就是&&。
        3.如果T为int&(左引用)，那么 T &&(int& &&) 就是&
        4.很明显，接受左值的话，T只能推导为int &。

        param既可以被初始化为左值引用，也可以被初始化为右值引用，取决于我们传递来的函数的实参类型。
        但是，当我们在函数func内部，将param传递给另一个函数的时候，此时，param是被当作左值进行传递的。
        因为这里的 param 是个具名的对象，必定是个左值
    */

    // f(param);//param是左值，最终只会调用f(T& param)

    f(std::forward<T>(param)); //std::forward<T>(param)将param转换成和T的类型一致
}
int main()
{
    printf("-----------------1.传入左值-------------------\n");
    int x = 10;
    func(x); //x被编译器推导为int&,即T=int& --> T&& =int& && --> param=int &

    printf("\n---------------2.传入左值引用-------------------\n");

    int &xx = x;
    func(xx); // T=int& --> T& &&=int& && --> param=int&

    printf("\n---------------3.传入右值-------------------\n");
    func(10); //T=int --> T&&=int && --> param=int &&,但是在使用param时，param变为左值

    int &&y = 20;
    // func(y);//注意：y类型是右值引用，但是本身实际上是个左值,所以传过去的y按左值引用处理
    func(std::move(y)); // T=int&&-->T&& &&=int && && ->param=int &&
    func(std::forward<int &&>(y));//将y强转成右值引用类型，即T=int&&

    return 0;
}