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
 *
 * 对于简单类型来说（没有析构函数的），使⽤ new 分配后，不管是数组数组还是⾮数组形式，两种⽅式都可以释放内存
 * 对于⾃定义类型来说，需要对单个对象使⽤ delete ，
 *      对于对象数组使⽤ delete [] ，逐个调⽤数组中对象的析构函数，从⽽释放所有内存；
 *      如果反过来使⽤，即对于单个对象使⽤ delete [] ，对于对象数组使⽤ delete ，其⾏为是未定义的；
 *
 * 所以，最恰当的⽅式是成对使用：new/delete, new[]/delete[]
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
    printf("\n----------------1 new/delete 简单类型--------------------\n");
    int *a = new int(1);
    delete a;

    int *b = new int(2);
    delete[] b;

    int *c = new int[11];
    delete c;
    
    int *d = new int[12];
    delete[] d;

    printf("\n----------------2.1 new/delete 自定义类型--------------------\n");
    Person *p = new Person();
    delete p;

    printf("\n----------------2.2 new[]/delete[] 自定义类型--------------------\n");
    Person *p2 = new Person[3];
    delete[] p2;

    printf("-------------code end---------------\n");
    return 0;
}