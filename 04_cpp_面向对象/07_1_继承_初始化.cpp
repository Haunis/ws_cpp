/*
 *	子类默认调用父类无参构造，但是也可以指定调用父类的构造
 *	指定调用父类构造；zi():fu(){}   
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Father
{
public:
	Father()
	{
		printf("Father 无参构造调用 \n");
	}
	Father(string str)
	{
		printf("Father 有参构造调用: %s\n", str.data());
	}

public:
	virtual void play()
	{
		printf("Father play ...\n");
	}
};

class Son : public Father
{
public:
	Son(string str) //默认调用父类无参构造
	{
		printf("Son 有参构造调用  \n");
	}
};

class Daughter : public Father
{
public:
	Daughter(string str) : Father(str)
	{ 
		printf("Daughter 有参构造调用 \n");
	}

public:
	void play();//重写父类方法
};
void Daughter::play() //必须在类里声明,方可再此定义
{
	printf("Daughter play ... \n");
	
}
int main()
{
	printf("----------------1.默认调用父类无参构造--------------\n");
	Son son("li lei");
	printf("sizeof(son)=%d\n", sizeof(son));
	son.play();

	printf("\n----------------2.指定调用父类构造--------------\n");
	Daughter daughter("han mei mei ");
	daughter.play();
	return 0;
}
