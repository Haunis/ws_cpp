/**
 * 参考：
 *      https://blog.csdn.net/linqingwu75/article/details/40951183
 *      https://bbs.csdn.net/topics/392044647?page=1
 *  
 *  访问 delete 之后的内存是一个未定义行为。
 *  未定义行为可能产生任何结果，包括但不限于：产生期望的结果，产生未期望的结果，产生随机的结果，
 *       产生无法解释的结果，运行错误，随机的运行时错误，编译错误，等等
 * 
 *  delete后访问非虚函数：
 *      非虚函数的调用地址在编译期间就已经确定，而且非虚函数的地址只跟类定义本身有关，与具体的实例对象无关
 *      所以当对象的内存会销毁掉，并不会影响到对其非虚函数的调用。
 * 
 *  delete后访问虚函数，成员变量会crash：
 *      虚函数是延迟绑定的，实例对象通过虚表指针访问虚函数表里的虚函数
 *      虚表指针式在对象的前4个字节里面。那么当对象被销毁时，其虚表指针就被销毁，虚函数自然是无从引用了。
 * 
 */
#include<stdio.h>
#include<iostream>
using namespace std;

class Person
{
public:
    int age;

public:
    Person(int age = -1)
    {
        this->age = age;
    }
    void func()
    {
        printf("func ... \n");
    }
    virtual void funcVirtual()
    {
        printf("funcVirtual ...\n");
    }

    ~Person(){
        cout<<"析构函数 this="<<this<<endl;
    }
};
int main(int argc, char *argv[])
{
    Person *p = new Person(28);
    Person *temp = p;

    cout<<"删除前 p = "<<p<<endl;
    cout<<"删除前 temp = "<<temp<<endl;
    delete temp; //实体对象会被释放
    cout<<"删除后 temp = "<<temp<<endl;
    cout<<"删除后 p = "<<p<<endl;

    // delete p; //error;  double free detected in tcache 2
    p = nullptr;
    p->func();
    // p->funcVirtual();//error,crash
    // int temp = p->age;//crash

    cout<<"\n赋值nullptr后， p = "<<p<<endl;

    return 0;
}