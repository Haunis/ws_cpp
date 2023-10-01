/*
 *  Created on: 2019年3月8日
 *	
 *	所有cpp文件均参与编译，f5	
 *
 *	参考：https://www.cnblogs.com/zhoug2020/p/5972439.html
 *
 *	名空间的作用：将一组全局范围有效的类、对象或数组组织到一个名字下面
 *
 *	命名空间可以声明多次
 *	不同的文件或者同一个文件可以有相同的命名空间，命名空间最好不要定义变量，
 *
 *	不同命名空间string类型变量同名的，要用域限定符::访问,也可以using mainspace1后直接访问
 *
 *	命名空间的变量仍是全局变量，只不过隐藏在指定的命名空间而已
 */

#include <iostream>
#include <stdio.h>
#include <cstdio> //相当于c中的stdio.h？？

#include "mySpace.h"
#include "one_four_space.h"
#include "temp_space.h"

namespace mySpace //可以声明多次
{
	void func3()
	{
		printf("func3 ...\n");
	}
} // namespace mySpace

using namespace std;

using namespace first::second::third::fourth;
using namespace mySpace;

int main()
{
	printf("--------------------1.first::second::third::fourth---------------------\n");
	// char *name = space_name;//error;mySpace也声明了该变量
								//两个名空间定义相同名称的变量，并且都使用using声明使用，所以不能直接访问，要使用限定符访问
	char *name = first::second::third::fourth::space_name; //使用限定符访问名空间内容
	printf("name=%s\n", name);

	func1(); //using namespace first::second::third::fourth后，可以直接访问

	Person p("lee");
	p.play();

	printf("\n----------------------2.mySpace--------------------------------------\n");
	char *mySpace_name = mySpace::space_name; //使用限定符访问名空间内容
	printf("mySpace_name=%s\n", mySpace_name);
	func2();
	func3();

	printf("\n---------------------3.temp_space------------------------------\n");
	{ //名空间只在其被声明的语句块内有效--就是{}内的范围
		using namespace tempspace1;
		cout << "var= " << var << endl; //mainspace1和mainspace2都有定义
		//不同命名空间有相同变量的，注意使用域限定符访问变量
		cout << "tempspace1::space_name =" << tempspace1::space_name << endl;
		//		cout << "space_name =" << space_name << endl;//报错,因为mySpace也定义了该变量

		cout << "space_name2=" << space_name2 << endl; //定义在第二个tempspace1
	}
	printf("\n-------\n");
	{
		using namespace tempspace2;
		cout << "var= " << var << endl; //mainspace1和mainspace2都有定义
		cout << "space_name =" << tempspace2::space_name << endl;

		int var = 55; //可以重定义
		cout << "var= " << var << endl;
	}

	return 0;
}
