/**
 * @date 2023-07-19
 * 
 *  多态的析构顺序： 子类析构 --> 父类析构
 *      父类指针指向子类对象，delete父类指针后，先调用指针指向的子类析构，子类析构自动调用父类析构
 *  
 *  父类析构函数一般写成虚函数的原因：
 *      如果析构函数不被声明成虚函数，则编译器实施静态绑定
 *      在删除父类指针时，只会调⽤父类的析构函数⽽不调⽤子类类析构函数，这样就会造成子类对象析构不完全，造成内存泄漏
 *      所以父类的析构函数一般声明成虚函数
 */
#include <stdio.h>

class Fu
{
public:
    Fu()
    {
        printf("Fu 构造 ,this = %p\n", this);
    }

    ~Fu()
    {
        printf("Fu 析构.. this = %p\n", this);
    }
};
class Zi : public Fu
{
public:
    Zi()
    {
        printf("Zi 构造  this = %p\n", this);
    }

    ~Zi()
    {
        printf("Zi 析构.. this = %p\n", this);
    }
};


class FuVirtual
{
public:
    FuVirtual()
    {
        printf("FuVirtual 构造 ,this = %p\n", this);
    }

    virtual ~FuVirtual()
    {
        printf("FuVirtual 虚析构.. this = %p\n", this);
    }
};
class ZiVirtual : public FuVirtual
{
public:
    ZiVirtual()
    {
        printf("ZiVirtual 构造  this = %p\n", this);
    }

    virtual ~ZiVirtual()
    {
        printf("ZiVirtual 虚析构.. this = %p\n", this);
    }
};

int main()
{
    printf("\n----------------1.1 无虚拟析构，无多态-------------------\n");
    // Zi 和 Fu 都会正常析构; 
    // 析构顺序： 子析构 -> 父析构
    Zi *zp;
    {
        zp = new Zi();
    }
    printf("\ndelete zp.....\n");
    delete zp; // 手动执行delete后才调用对象的析构

    printf("\n----------------1.2 无虚拟析构，有多态-------------------\n");
    // 子类不能析构
    Fu *fp;
    {
        fp = new Zi();
    }
    printf("\ndelete fp.....\n");
    delete fp; // 手动执行delete后才调用对象的析构

    printf("\n----------------2.1 有虚拟析构，无多态-------------------\n");
    // ZiVirtual 和 FuVirtual 都会正常析构
    ZiVirtual *zp_v;
    {
        zp_v = new ZiVirtual();
    }
    printf("\ndelete zp_v.....\n");
    delete zp_v; 

     printf("\n----------------2.2 有虚拟析构，有多态-------------------\n");
    // ZiVirtual 和 FuVirtual 都会正常析构
    FuVirtual *f_zp_v;
    {
        f_zp_v = new ZiVirtual();
    }
    printf("\ndelete f_zp_v.....\n");
    delete f_zp_v; 

    printf("\n----------------code end-------------------\n");
    return 0;
}