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

class Teacher
{
public:
    int age;

public:
    Teacher(int age = -1) : age{age}
    {
        printf("Teacher 构造 age=%d, this = %#x\n", age, this);
    }
    ~Teacher()
    {
        printf("Teacher 析构.. this = %#x\n", this);
    }
};

class Outer
{
public:
    Teacher t;
    int age;
public:
    Outer():age{18}
    {
        printf("Outer 构造.. this = %#x\n", this);
    }
    ~Outer()
    {
        printf("Outer 析构.. this = %#x\n", this);
    }
};

int main()
{

    printf("\n----------------1. 栈区对象-------------------\n");
    {
        Teacher t(18);
    }
    printf("\n----------------2. new 对象-------------------\n");
    Teacher *tp;
    {
        tp = new Teacher(12);
    }
    printf(".....\n");
    delete tp; // 手动执行delete后才调用对象的析构

    printf("\n----------------3. 成员对象析构比本对象晚 -------------------\n");
    {
        Outer o;     
        printf("o.age=%d, &o = %#x\n",o.age, &o);   
        printf("o.t.age=%d, &o.t = %#x\n",o.t.age, &(o.t));  //p和p.t地址是一样的... 

        Outer *op = &o;
        printf("op->age=%d \n",op->age);  

        // Teacher *tpp = &o.t;
        Teacher *tpp = (Teacher*)&o; //强转成Teacher指针也行，地址都一样...
        printf("tpp->age=%d \n",tpp->age);  
    }
    printf("\n----------------code end-------------------\n");

    return 0;
}