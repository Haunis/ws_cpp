/**
 *  参考：   
 *      https://www.cnblogs.com/WindSun/p/11444429.html
 *  
 * 
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Counter
{
public:
    int shared_count; //share_ptr的引用计数
    int weak_count;   //weak_ptr的引用计数
public:
    Counter() : shared_count(0), weak_count(0)
    {
        printf("Counter 构造 %#x\n", this);
    }

    ~Counter()
    {
        printf("Counter 析构..%#x\n", this);
    }
};

template <class T>
class WeakPtr; //为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用

//------------------------------------SharedPtr------------------------------------
template <class T>
class SharePtr
{
public:
    T *m_ptr;           //要管理的对象的指针
    Counter *p_counter; //计数器

public:
    friend class WeakPtr<T>; //方便weak_ptr与share_ptr设置引用计数和赋值

    SharePtr(T *p = 0) : m_ptr(p)
    {
        p_counter = new Counter();
        if (p)
            p_counter->shared_count = 1;
        cout << "SharePtr 指针构造，this=" << this << ",p_counter->shared_count: " << p_counter->shared_count << endl;
    }

    SharePtr(SharePtr<T> const &other) //复制构造
    {
        m_ptr = other.m_ptr;
        (other.p_counter)->shared_count++;
        cout << "SharePtr 拷贝构造,this=" << this << ",other_shared_count=" << (other.p_counter)->shared_count << endl;
        p_counter = other.p_counter;
    }
    SharePtr(WeakPtr<T> const &weakPtr) //weak_ptr的lock()生成share_ptr用
    {
        m_ptr = weakPtr.m_ptr;
        (weakPtr.p_counter)->shared_count++;
        cout << "SharePtr WeakPtr构造，this=" << this << ",weakPtr_shared_count= " << (weakPtr.p_counter)->shared_count << endl;
        p_counter = weakPtr.p_counter;
    }
    SharePtr<T> &operator=(SharePtr<T> &shared_count)
    {
        if (this != &shared_count)
        {
            release();
            (shared_count.p_counter)->shared_count++;
            cout << "SharePtr 赋值运算符， " << (shared_count.p_counter)->shared_count << endl;
            p_counter = shared_count.p_counter;
            m_ptr = shared_count.m_ptr;
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
    ~SharePtr()
    {
        printf("SharePtr 析构...%#x\n", this);
        release();
    }

protected:
    void release()
    {
        p_counter->shared_count--;
        int s_c = p_counter->shared_count;
        int w_c = p_counter->weak_count;
        cout << "SharePtr release...s_c=" << s_c << ",w_c=" << w_c << endl;
        if (p_counter->shared_count < 1)
        {
            delete m_ptr;
            if (p_counter->weak_count < 1) //只要管理的对象m_ptr不再使用了，计数器也要析构
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
    T *m_ptr; //作为中间变量，调用lock()时传给SharedPtr
    Counter *p_counter;

public:
    friend class SharePtr<T>; //方便weak_ptr与share_ptr设置引用计数和赋值

    WeakPtr() //给出默认构造和拷贝构造，其中拷贝构造不能有从原始指针进行构造
    {
        printf("WeakPtr 空构造，this=%#x\n", this);
        m_ptr = 0;
        p_counter = 0;
    }
    WeakPtr(SharePtr<T> &shared_count) : m_ptr(shared_count.m_ptr), p_counter(shared_count.p_counter)
    {
        cout << "weakPtr SharedPtr构造,this=" << this << endl;
        p_counter->weak_count++;
    }
    WeakPtr(WeakPtr<T> &weakPtr) : m_ptr(weakPtr.m_ptr), p_counter(weakPtr.p_counter)
    {
        cout << "weakPtr weakPtr构造,this=" << this << endl;
        p_counter->weak_count++;
    }
    ~WeakPtr()
    {
        printf("WeakPtr 析构，this=%#x\n", this);
        release();
    }
    WeakPtr<T> &operator=(WeakPtr<T> &weakPtr)
    {
        cout << "weakPtr赋值运算,参数：weakPtr" << endl;
        if (this != &weakPtr)
        {
            release();
            p_counter = weakPtr.p_counter;
            p_counter->weak_count++;
            m_ptr = weakPtr.m_ptr;
        }
        return *this;
    }
    WeakPtr<T> &operator=(SharePtr<T> &sharedPtr)
    {
        cout << "weakPtr赋值运算，参数：sharedPtr" << endl;
        release();
        p_counter = sharedPtr.p_counter;
        p_counter->weak_count++;
        m_ptr = sharedPtr.m_ptr;
        return *this;
    }
    SharePtr<T> lock()
    {
        printf("WeakPtr lock..\n");
        return SharePtr<T>(*this);
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

protected:
    void release()
    {
        if (p_counter)
        {
            p_counter->weak_count--;
            cout << "weakptr release," << p_counter->weak_count << endl;
            if (p_counter->weak_count < 1 && p_counter->shared_count < 1)
            {
                //delete p_counter;
                p_counter = NULL;
            }
        }
    }
};

class Person
{
public:
    string name;
    // std::shared_ptr<Person> m_partner;//shared_ptr持有Person指针，导致循环引用，Person最后不会被析构
    WeakPtr<Person> m_partner; //不会持有Person指针,只是旁观者,使用的时候lock()可获取该对象的引用
public:
    Person(const string &name) : name{name}
    {
        printf("Person 构造 name=%s, this=%#x\n", name.data(), this);
    }

    virtual ~Person()
    {
        printf("Person 析构 --> name=%s, this=%#x\n", name.data(), this);
    }

    friend bool partnerUp(SharePtr<Person> &p1, SharePtr<Person> &p2)
    {
        cout << "Person partnerUp... " << endl;
        if (!p1.m_ptr || !p2.m_ptr)
        {
            return false;
        }

        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << "Person partnerUp... " << p1->name << " is now partenered with " << p2->name << endl;
        return true;
    }
};

int main()
{
    printf("-----------------1.循环引用-------------------\n");
    {
        Person *pPerson1 = new Person("lee1");
        Person *pPerson2 = new Person("lee2");
        SharePtr<Person> p1(pPerson1);
        SharePtr<Person> p2(pPerson2);
        partnerUp(p1, p2); // 互相设为伙伴

        string p1_partner_name = p1->m_partner.lock()->name;
        cout << "p1_partner_name=" << p1_partner_name << endl;
        // printf("p1.user_count = %d\n", p1.use_count());
        // printf("p2.user_count = %d\n", p2.use_count());
    }

    printf("\n----------------code end-------------------\n");

    //	cin.ignore(1);
    return 0;
}
