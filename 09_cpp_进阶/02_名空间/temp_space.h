/*
 * temp_space.h
 *
 *  Created on: Jun 5, 2020
 *      Author: haunis
 */

#ifndef TEMP_SPACE_H_
#define TEMP_SPACE_H_
#include <stdio.h>
#include <iostream>
using namespace std;

namespace tempspace1
{
	string space_name = "tempspace1,first";

	int var = 111; //仍是全局变量，只不过隐藏在指定的命名空间而已
	void printSpace()
	{
		printf("tempspace1\n");
	}
} // namespace tempspace1

namespace tempspace1 //第二次声明,可以声明多次。
{
	string space_name2 = "tempspace1,second";
}

//////////////////////////tempspace2////////////////////////////////
namespace tempspace2
{
	string space_name = "tempspace2";
	int var = 222;
} // namespace tempspace2

#endif /* TEMP_SPACE_H_ */
