/*
 * mynamespace.h
 *
 *  Created on: Mar 13, 2020
 *      Author: haunis
 */

#ifndef ONE_FOUR_SPACE_H_
#define ONE_FOUR_SPACE_H_

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

namespace first
{
	namespace second
	{
		namespace third
		{
			namespace fourth
			{

				extern char *space_name; //必须要声明，在其他地方才可以使用此命名空间的space_name;

				void func1();

				class Person
				{
				private:
					string name;

				public:
					Person(string name);
					~Person();

				public:
					void play();
				};

			} // namespace fourth
		}	  // namespace third
	}		  // namespace second
} // namespace first

#endif /* ONE_FOUR_SPACE_H_ */
