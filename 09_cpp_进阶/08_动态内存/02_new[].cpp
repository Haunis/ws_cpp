/**
 * 参考：https://blog.csdn.net/hazir/article/details/21413833#t0
 * 
 * new 和new[]区别：
 *      new: 在堆内存上申请指定类型的内存大小，并调用对象的构造函数初始化对象
 *           如果不是new对象的话，只需申请内存大小，无需调用构造函数，如：new int(0 );
 *      new[num]:在堆上申请num*申请类型内存大小，并调用每个对象的构造函数
 *               和new 一样，如果类型不是对象的话，无需调用构造函数，如new int[10]; 
 * delete和delete[]:
 *      delete:调用对象析构（如果是对象的话），调用标准库函数operator delete释放对象
 *      delete[]:调用每个对象的析构（如果是对象的话），调用标准库函数operator delete释放对象
 * 
 * 所以 new/delete, new[]/delete[]要成对使用； 当然，如果是基本类型（没有析构函数的）new[]/delete也是可以使用的
 * 
 */
#include <iostream>
#include <stdio.h>

using namespace std;
class Person
{

public:
    string name;
    int age;

public:
    Person()
    {
        printf("Person 构造, this=%#x\n", this);
    }
    ~Person()
    {
        printf("Person 析构--> this=%#x\n", this);
    }
};

int main(int argc, char *argv[])
{
    printf("--------------------1.new/delete------------------------\n");
    Person *p = new Person();
    delete p;

    printf("\n--------------------2.new[]/delete[]------------------------\n");
    Person *p2 = new Person[3];
    delete[] p2;

    printf("-------------code end---------------\n");
    return 0;
}