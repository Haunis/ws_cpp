/**
 * @date 2023-07-21
 *
 * 参考：https://zhuanlan.zhihu.com/p/354046948
 *
 * 将 new 和 delete 重载为 private 。
 *
 */
#include <stdio.h>
#include <stdlib.h> //malloc
#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        printf("构造...\n");
    }

    ~Person()
    {
        printf("析构...\n");
    }

    void func()
    {
        printf("func ...\n");
    }

private:
    void *operator new(std::size_t size)
    {
        cout << "new .." << size << endl;
        return std::malloc(size);
    }
    void operator delete(void *ptr)
    {
        std::cout << "operator delete" << std::endl;
        std::free(ptr);
    }
};

int main()
{
    Person p;//可创建栈对象

    // Person *pp = new Person;//error, 不可创建堆对象， new和delete 操作符已被重载为private

    return 0;
}