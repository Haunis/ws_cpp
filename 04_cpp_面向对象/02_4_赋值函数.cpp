/**
 * 参考：https://www.cnblogs.com/alantu2018/p/8459250.html
 * 
 * 赋值函数: = 
 * 
 * 调用时机： 对象已经初始化，再使用 本对象=其他对象 时，会调用本对象的赋值函数
 *      
 * 
 */
#include <stdio.h>

using namespace std;
class Person
{
public:
    int age;

public:
    Person(int age)
    {
        this->age = age;
        printf("构造函数: age=%d, this=%#x\n", age, this);
    }
    Person(const Person &other) //可以不加const修饰
    {
        this->age = other.age;
        printf("复制构造: this=%#x, other=%#x\n", this, &other);
    }
    // Person &operator=(Person &&other)//移动赋值函数，参考左值引用demo
    Person &operator=(Person &other)
    {
        printf("赋值函数 this=%#x, &other=%#x\n", this, &other);
        this->age = other.age;
        return *this;
    }
    ~Person()
    {
        printf("析构--> this=%#x\n", this);
    }
};

int main(int argc, char *argv[])
{
    printf("------------------1.调用赋值函数------------------------\n");
    Person p1(1), p2(2);
    p1 = p2; //p1有初始化了以后，调用p1赋值函数

    printf("\n----------------2.调用复制构造函数------------------------\n");
    Person p3 = p1; //p3没有初始化，调用p3复制构造函数
    printf("p3.age = %d\n", p3.age);

    printf("\n------------------code end--------------------\n");
    return 0;
}