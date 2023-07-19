/**
 *  demo参考：
 *      https://www.cnblogs.com/WindSun/p/11444429.html
 *
 *  循环引用：
 *      https://blog.csdn.net/adam2021/article/details/129849022
 *
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Counter
{
public:
    int shared_count; // share_ptr的引用计数
    int weak_count;   // weak_ptr的引用计数
public:
    Counter() : shared_count(0), weak_count(0)
    {
        printf("Counter 构造 %p\n", this);
    }

    ~Counter()
    {
        printf("\nCounter 析构..%p\n", this);
    }
};

template <class T>
class WeakPtr; // 为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用

//------------------------------------SharedPtr------------------------------------
template <class T>
class SharedPtr
{
public:
    T *m_ptr;           // 要管理的对象的指针
    Counter *p_counter; // 计数器

public:
    friend class WeakPtr<T>; // 方便weak_ptr与share_ptr设置引用计数和赋值

    SharedPtr(T *p = 0) : m_ptr(p)
    {
        p_counter = new Counter();
        if (p)
            p_counter->shared_count = 1;
        cout << "SharedPtr 指针构造，this=" << this << ",p_counter->shared_count: " << p_counter->shared_count << endl;
    }

    SharedPtr(SharedPtr<T> const &other) // 复制构造
    {
        m_ptr = other.m_ptr;
        (other.p_counter)->shared_count++;
        cout << "SharedPtr 拷贝构造,this=" << this << ",other_shared_count=" << (other.p_counter)->shared_count << endl;
        p_counter = other.p_counter;
    }
    SharedPtr(WeakPtr<T> const &weakPtr) // weak_ptr的lock()生成share_ptr用
    {
        m_ptr = weakPtr.m_ptr;
        (weakPtr.p_counter)->shared_count++;
        cout << "SharedPtr WeakPtr构造，this=" << this << ",weakPtr_shared_count= " << (weakPtr.p_counter)->shared_count << endl;
        p_counter = weakPtr.p_counter;
    }
    SharedPtr<T> &operator=(SharedPtr<T> &shared_ptr)
    {
        printf("SharedPtr 赋值运算符,this=%p,other=%p\n", this, &shared_ptr);
        if (this != &shared_ptr)
        {
            release(); // 将对m_ptr的引用计数减1
            (shared_ptr.p_counter)->shared_count++;
            printf("SharedPtr 赋值运算符， s_c=%d\n\n", (shared_ptr.p_counter)->shared_count);
            p_counter = shared_ptr.p_counter;
            m_ptr = shared_ptr.m_ptr;
        }
        return *this;
    }

    T &operator*()
    {
        return *m_ptr;
    }
    T *operator->()
    {
        return m_ptr;
    }
    ~SharedPtr()
    {
        printf("\nSharePtr 析构...%p\n", this);
        release();
    }

protected:
    void release()
    {
        p_counter->shared_count--;
        int s_c = p_counter->shared_count;
        int w_c = p_counter->weak_count;
        cout << "SharedPtr release...s_c=" << s_c << ",w_c=" << w_c << " p_counter:"<<p_counter<<endl;
        if (p_counter->shared_count < 1)
        {
            delete m_ptr;                  // 会调用对象的析构函数
            if (p_counter->weak_count < 1) // 只要管理的对象m_ptr不再使用了，计数器也要析构
            {
                delete p_counter;
                p_counter = NULL;
            }
        }
    }
};

//------------------------------------WeakPtr------------------------------------
template <class T>
class WeakPtr
{
private:
    T *m_ptr; // 作为中间变量，调用lock()时传给SharedPtr
    Counter *p_counter;

public:
    friend class SharedPtr<T>; // 方便weak_ptr与share_ptr设置引用计数和赋值

    WeakPtr() // 给出默认构造和拷贝构造，其中拷贝构造不能有从原始指针进行构造
    {
        printf("WeakPtr 空构造，this=%p\n", this);
        m_ptr = 0;
        p_counter = 0;
    }
    WeakPtr(SharedPtr<T> &shared_count) : m_ptr(shared_count.m_ptr), p_counter(shared_count.p_counter)
    {
        cout << "weakPtr SharedPtr构造,this=" << this << endl;
        p_counter->weak_count++;
    }
    WeakPtr(WeakPtr<T> &weakPtr) : m_ptr(weakPtr.m_ptr), p_counter(weakPtr.p_counter)
    {
        cout << "weakPtr weakPtr构造,this=" << this << endl;
        p_counter->weak_count++;
    }
    WeakPtr<T> &operator=(WeakPtr<T> &weakPtr)
    {
        printf("weakPtr 赋值运算(weakPtr), this=%p,other=%p\n", this, &weakPtr);
        if (this != &weakPtr)
        {
            release();
            p_counter = weakPtr.p_counter;
            p_counter->weak_count++;
            m_ptr = weakPtr.m_ptr;
        }
        return *this;
    }
    WeakPtr<T> &operator=(SharedPtr<T> &sharedPtr)//本demo走这个地方
    {
        printf("weakPtr 赋值运算(sharedPtr), this=%p, &sharedPtr=%p\n", this, &sharedPtr);
        release();
        p_counter = sharedPtr.p_counter;
        p_counter->weak_count++;
        printf("weakPtr 赋值运算， w_c=%d\n\n", p_counter->weak_count);
        m_ptr = sharedPtr.m_ptr;
        return *this;
    }
    SharedPtr<T> lock()
    {
        printf("WeakPtr lock..\n");
        return SharedPtr<T>(*this);
    }
    bool expired()
    {
        if (p_counter)
        {
            if (p_counter->shared_count > 0)
            {
                cout << "empty" << p_counter->shared_count << endl;
                return false;
            }
        }
        return true;
    }
    ~WeakPtr()
    {
        printf("WeakPtr 析构，this=%p\n", this);
        release();
    }

protected:
    void release()
    {
        if (p_counter)
        {
            p_counter->weak_count--;
            int s_c = p_counter->shared_count;
            int w_c = p_counter->weak_count;
            cout << "weakptr release...s_c=" << s_c << ",w_c=" << w_c <<", p_counter="<<p_counter<< endl;
            if (p_counter->weak_count < 1 && p_counter->shared_count < 1)
            {
                delete p_counter;
                p_counter = NULL;
            }
        }
    }
};

class Person
{
public:
    string name;
    // std::shared_ptr<Person> m_partner;//会增加shared_ptr引用计数，导致循环引用，Person最后不会被析构
    // SharedPtr<Person> m_partner; // 会增加SharePtr引用计数，导致SharePtr析构时不能调用delete m_ptr
    //  因此导致Person最后不会被析构
    WeakPtr<Person> m_partner; // 不会增加SharePtr引用计数; 调用WeakPtr.lock()可获取SharePtr；
    //                             // Person析构后，m_partner才会析构
    //                             // 析构顺序：SharePtr delete m_ptr ---> Person析构 ---> m_partner析构
public:
    Person(const string &name) : name{name}
    {
        printf("Person 构造 name=%s, this=%p\n\n", name.data(), this);
    }

    virtual ~Person()
    {
        printf("Person 析构 --> name=%s, this=%p\n", name.data(), this);
    }

    friend bool partnerUp(SharedPtr<Person> &p1, SharedPtr<Person> &p2)
    {
        string split = "===============\n";
        cout << "\nPerson partnerUp start " + split << endl;
        if (!p1.m_ptr || !p2.m_ptr)
        {
            return false;
        }

        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << "Person partnerUp end " + split << endl;
        return true;
    }
};

int main()
{
    printf("-----------------1.循环引用-------------------\n");
    {
        Person *pPerson1 = new Person("lee1");
        Person *pPerson2 = new Person("lee2");
        SharedPtr<Person> p1(pPerson1);
        SharedPtr<Person> p2(pPerson2);
        partnerUp(p1, p2); // 互相设为伙伴

        string p1_partner_name = p1->m_partner.lock()->name; // m_partner为WeakPtr时
        // string p1_partner_name = p1->m_partner->name; //m_partner为SharedPtr时
        cout << "p1_partner_name=" << p1_partner_name << endl;
        // printf("p1.user_count = %d\n", p1.use_count());
        // printf("p2.user_count = %d\n", p2.use_count());
    }

    printf("\n----------------code end-------------------\n");

    //	cin.ignore(1);
    return 0;
}
