#include <stdio.h>


void (*g_fun)(const char *) = nullptr; //定义一个全局函数指针

void setCallback(void (*fun)(const char*))
{
    g_fun = fun;
}

void executeCallback(const char* arg)
{
    if (g_fun != nullptr)
    {
        g_fun(arg);
    }
    else
    {
        printf("callback fun is null");
    }
}

class Person
{
public:
    static void eat(const char* arg) //使用char*会警告
    {
        printf("eat --> %s\n",arg);
    }
};

int main(int argc, char *argv[])
{
    setCallback(Person::eat);
    executeCallback("bread");

    return 0;
}