/*
 * test_demo.h
 *
 *  Created on: Apr 28, 2020
 *      Author: haunis
 */

#ifndef SRC_TEST_DEMO_H_
#define SRC_TEST_DEMO_H_

/*static*/ void print_test() //只被include一次,所以可以不用static修饰
{
	printf("print_test\n");
	test_fun(); //虽然未include compute.h 但是在main中,compute.h已经被include
}

#endif /* SRC_TEST_DEMO_H_ */
