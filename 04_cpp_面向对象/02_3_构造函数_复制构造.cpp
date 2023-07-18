/**
 * 参考：https://www.cnblogs.com/alantu2018/p/8459250.html
 *
 * 复制构造函数(也叫拷贝构造):
 *      Person(const Person &p){}
 *
 * 复制构造函数调用时机：
 *      1.等于号"="赋值给一个对象时; 如：Person p2=p1
 *      2.函数的参数为对象时
 *      3.函数的返回值为类的对象时（编译器会自动优化，使用-fno-elide-constructors可观察临时值）
 *
 * 禁用复制构造：
 *      Person(const Person &p) = delete; //禁用复制构造函数
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
        printf("构造函数: this=%#x\n", this);
    }
    Person(const Person &other) // 可以不加const修饰
    {
        this->age = other.age;
        printf("复制构造: this=%#x, other=%#x\n", this, &other);
    }
    Person p_func()
    {
        return *this; //会调用复制构造
    }

    // Person(const Person &p) = delete; //禁用复制构造函数,就是禁用Person p2 = p1这样的赋值
    ~Person()
    {
        printf("析构--> this=%#x\n", this);
    }
};
void func(Person p) // 复制构造函数会被调用一次
{
    // printf("func -->%#x\n", p);//会再次创建个对象....
    printf("func -->%#x\n", &p);
}
Person func2()
{
    Person p(20);
    return p; // 非引用返回的临时变量，是右值
}
int main(int argc, char *argv[])
{
    Person p1(10);
    printf("&p1=%#x\n", &p1);
    printf("-----------------1.使用=对对象进行赋值----------------------\n");
    Person p2 = p1; // 会调用复制构造进行复制

    printf("\n---------------2.函数参数为对象----------------------\n");
    func(p1);
    printf("\n---------------3.函数返回对象时----------------------\n");
    func2();//由于编译器的优化，不调用复制构造

    printf("\ncall p1.p_func() ... \n");
    p1.p_func();//调用复制构造

    printf("\n------------------code end--------------------\n");
    return 0;
}