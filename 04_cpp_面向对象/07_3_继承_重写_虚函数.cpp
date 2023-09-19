/*	
 *  参考：
 *      https://www.cnblogs.com/zkfopen/p/11061414.html
 * 
 *  虚拟函数：
 *      用virtual修饰的函数;子类可以重写
 *       
 *	纯虚拟函数：
 *      用virtual修饰的并且没有函数体的
 *      如: virtual void fun(void)=0; 与Java里的抽象方法类似
 *
 *	抽象基类：有纯虚拟函数的类
 *
 *	虚函数原理:
 *		编译器处理虚函数:
 *      为每个类(包括基类和子类)增加一个隐藏成员,该隐藏成员保存一个指向<函数地址数组>的指针
 *      该指针称为<虚表指针>,该函数地址数组称为<虚函数表>
 * 
 *		如果子类未重写基类的虚函数,则该虚函数表保存基类中未被重写的虚函数的地址.
 *		如果子类重写了基类的虚函数,该虚函数表保存子类重写后的函数的地址,而不是基类的虚函数地址
 *      注意，如果子类中定义了新的虚方法，则该虚函数的地址也将被添加到派生类虚函数表中
 */

#include <stdio.h>

class Fu //抽象基类
{
public:
    void play() //普通函数,子类不可重写
    {
        printf("fu play .. \n");
    }
    virtual void virPlay() //虚拟函数,子类可重写
    {
        printf("fu virPlay .. \n");
    }
    virtual void eat(void) = 0; //纯虚拟函数,子类必须重写
};

class Zi : public Fu
{
public:
    void play() //不可重写父类普通函数
    {
        printf("zi play ..\n");
    }
    void virPlay() //可以重写父类虚拟函数
    {
        printf("zi virPlay .. \n");
    }
    void eat() //必须重写父类纯虚拟函数
    {
        printf("zi eat .. \n");
    }
};

int main(int argc, char *argv[])
{
    Zi zi;
    zi.play();
    zi.virPlay();
    zi.eat();
    return 0;
}