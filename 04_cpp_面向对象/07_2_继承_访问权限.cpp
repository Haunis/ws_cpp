/**
 * 		访问权限总结
 * 			默认是private修饰: class ZiPrivate : private Fu
 * 
 * 			一，父类成员变量：
 * 			父类成员变量权限	private	protected	public
 * 
 * 			private:子类内		×		√			√
 *  		private:子类外		×		×			×
 * 
 * 			protected:子类内	×		√			√
 * 			protected:子类外	×		×			×
 * 
 * 			public：子类内		×		√			√
 * 			public：子类外		×		×			√
 * 			
 *
 * 			注意：
 * 			 	子类内指的是：在子类方法内访问父类成员
 * 							如:ziFun(){return fuMember;} zi.ziFun()调用
 * 				子类外指的是：子类实例化好的对象直接访问父类成员
 * 							如：zi.fuMember在外部如main函数里调用
 *
 * 			ziPrivate和protected访问权限一样,都是只能在类的内部访问父类protected,public成员
 * 				不能使用实例访问父类成员
 * 			public子类在自己方法内访问父类成员和private,protected一样
 * 				但是可以使用实例访问public的成员
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Fu
{
private:
	string privateMember = "p1"; //子类内部不可访问。只有本类内部和public的子类可在本类内部访问--publicFuFun();
protected:
	string protectedMember = "p2"; //在子类内部可以访问，子类外部不可访问
public:
	string publicMember = "p3"; //在子类内部可以访问，public的子类在外部可访问
private:
	void privateFuFun() //只能在此类内部访问
	{
		printf("privateFuFun called\n");
	}

public:
	string publicFuFun() //本类可以访问；public的子类可以访问
	{
		printf("fu publicFuFun .....");
		return privateMember;
	}
};
//private/protected/public Fu，描述的是子类的访问权限
class ZiPrivate : private Fu
{
public:
	void func()
	{
		// string pri_val = privateMember;//error; 不可访问父类私有成员
		string pro_val = protectedMember;
		string pub_val = publicMember;

		printf("func --> pro_val = %s\n", pro_val.data());
		printf("func --> pub_val = %s\n", pub_val.data());
	}
};

class ZiProtected : protected Fu
{

public:
	void func()
	{
		// string pri_val = privateMember;//error; 不可访问父类私有成员
		string pro_val = protectedMember;
		string pub_val = publicMember;

		printf("func --> pro_val = %s\n", pro_val.data());
		printf("func --> pub_val = %s\n", pub_val.data());
	}
};

class ZiPublic : public Fu
{
public:
	void func()
	{
		// string pri_val = privateMember;//error; 不可访问父类私有成员
		string pro_val = protectedMember;
		string pub_val = publicMember;

		printf("func --> pro_val = %s\n", pro_val.data());
		printf("func --> pub_val = %s\n", pub_val.data());
	}
};



int main()
{
	Fu fu;
	ZiPrivate ziPrivate;
	ZiProtected ziProtected;
	ZiPublic ziPublic;

	printf("-------------------1.ziPrivate-----------------------\n");

	ziPrivate.func(); //ok; 可以在方法内部访问父类成员

	//私有权限的子类,在子类外不可访问一切父类成员
	// string pri_val = ziPrivate.privateMember;//error
	// string pro_val = ziPrivate.protectedMember;//error
	// string pub_val = ziPrivate.publicMember;/error
	// ziPrivate.publicFuFun();//error

	printf("\n-----------------2.ziProtected-----------------------\n");

	ziProtected.func(); //ok; 可以在方法内部访问父类成员

	//protected的子类,在子类外不可访问一切父类成员;和ziPrivate权限一样
	// string pri_val = ziProtected.privateMember;//error
	// string pro_val = ziProtected.protectedMember;//error
	// string pub_val = ziProtected.publicMember;//error
	// ziProtected.publicFuFun();//error

	printf("\n-----------------3.ziPublic-----------------------\n");

	ziPublic.func(); //ok; 可以在方法内部访问父类成员

	// string pri_val = ziPublic.privateMember;   //error
	// string pro_val = ziPublic.protectedMember; //error
	string pub_val = ziPublic.publicMember;//可以在父类外访问父类public成员
	printf("main pub_val:%s\n",pub_val.data());
	ziPublic.publicFuFun(); //ok

	return 0;
}
