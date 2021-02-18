/*
 * mynamespace.cpp
 *
 *  Created on: Mar 13, 2020
 *      Author: haunis
 */
#include "one_four_space.h"

namespace first
{
	namespace second
	{
		namespace third
		{
			namespace fourth
			{

				char *space_name = "one_four";

				void func1()
				{
					printf("func1 ...\n");
				}
				Person::Person(string name)
				{
					this->name = name;
				}
				Person::~Person() {}
				void Person::play()
				{
					printf("%s play \n", this->name.data());
				}

			} // namespace fourth
		}	  // namespace third
	}		  // namespace second
} // namespace first
