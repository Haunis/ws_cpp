/**
 *https://www.cnblogs.com/yuehouse/p/10116691.html
 *
 * rand():
 * 		返回一个从0到最大随机数的任意整数，最大随机数的大小通常是固定的一个大整数
 * 
 * 		产生0～99随机整数： rand()%100
 * 		[a,b)随机整数： rand()%(b-a)+a
 * 
 * 
 * srand(int seed)：
 * 		给随机发生器提供种子。
 * 		rand()每次在调用的时候通过种子产生随机序列，如果种子不变化的话，每次调用rand()产生的随机序列都是一样的
 *  
 */

#include <stdio.h>
#include <cstdlib>
#include <ctime>

#define RANDOM(a, b) (rand() % (b - a) + a)

int main(int argc, char *argv[])
{

	// srand(time(0));//给随机数提供种子；默认seed=1,使用固定种子的话，每次程序执行生成一样的随机序列
	for (int i = 0; i < 30; i++)
	{
		int a = RANDOM(0, 8);//[0,8)
		printf("a : %d\n", a);
	}
	
	return 0;
}
