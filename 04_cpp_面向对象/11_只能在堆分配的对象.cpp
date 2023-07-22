/**
 * @date 2023-07-21
 *
 *  参考： https://blog.csdn.net/xxxtlxxx/article/details/127522422
 *
 *  如何让对象只能在堆上分配： 析构函数声明成private的即可
 *
 *  原因：
 *      C++是静态绑定的语言。在编译过程中，所有的非虚函数调用都必须分析完成。即使是虚函数，也需检查可访问性。
 *      因此，当在栈上生成对象时，对象会自动析构，也就说析构函数必须可以访问。
 *      而堆上生成对象，由于析构时机由程序员控制，所以不一定需要析构函数。
 *
 *  如何释放：
 *      提供一个成员函数，完成delete操作。在成员函数中，析构函数是可以访问的。当然detele操作也是可以编译通过。
 *
 */
#include <stdio.h>

class Person
{
public:
    Person()
    {
        printf("构造...\n");
    }

    void destory()
    {
        delete this;
    }

private:
    ~Person()
    {
        printf("析构...\n");
    }
};

int main()
{
    // Person p; // error; 不能创建栈对象，编译报错，析构函数不能访问

    Person *pp = new Person(); // 可以创建堆对象
    // delete pp; //error，无法访问析构
    pp->destory(); // 可以调用自定义函数进行析构

    return 0;
}