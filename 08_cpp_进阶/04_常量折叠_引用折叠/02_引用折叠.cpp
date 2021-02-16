/**
 * 参考：
 *      https://zhuanlan.zhihu.com/p/50816420
 *      https://www.zhihu.com/question/40346748
 * 
 * 折叠：就是多个的意思
 * 
 * 引用折叠具体规则是：
 *      1.所有右值引用折叠到右值引用上仍然是一个右值引用。（A&& && 变成 A&&）
 *      2.所有的其他引用类型之间的折叠都将变成左值引用。（A& & 变成 A&; A& && 变成 A&; A&& & 变成 A&）
 *      通俗地讲，左引用传染，只要有左引用就是左引用类型
 *  
 * 编译器不允许在代码中写： int& &&这种形式，但是编译器却可以自己使用
 * 
 * 万能引用：
 *      template <class T> void func(T &&param){}
 *      既可以接受左值，又可以接受右值
 *      万能引用就是利用模板推导和引用折叠的相关规则，生成不同的实例化模板来接收传进来的参数
 * 还有个"万能引用"的概念是 "const int& num" ,见左引用demo
 */

#include <stdio.h>
#include <typeinfo>
#include <iostream>
using namespace std;

template <class T>
void func(T &&param) //万能引用
{
    int ret = param;
    cout << ret << ", lvalue_ref_type?: " << is_lvalue_reference<T>::value << endl; //0 or 1
}

int main()
{
    printf("-----------------1.传入左值-------------------\n");
    int x = 10;
    func(x); //1； 传入后x被编译器推导为int&,即T:int& --> T&& :int& && --> param:int &

    printf("\n---------------2.传入左值引用-------------------\n");

    int &xx = x;
    func(xx); //1; 传入,T:int& --> T& &&:int& && --> param: int&

    printf("\n---------------3.传入右值-------------------\n");
    func(10); //0; 传入后T:int --> T&&:int && --> param:int &&

    int &&y = 20;
    // func(y);//注意：y类型是右值引用，但是本身实际上是个左值
    func(std::move(y)); //1 T:int&&-->T&& &&:int && && ->param:int &&??
 

    return 0;
}