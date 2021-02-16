/*
 *  Created on: Apr 8, 2020
 *  Author: haunis
 */

#ifndef TOOLS_H_
#define TOOLS_H_
#include <stdio.h>
#include <unistd.h>
int64_t getMilliSecond()     //毫秒
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
int64_t getMicroSecond()     //微妙
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

#endif /* TOOLS_H_ */
