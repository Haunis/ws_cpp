/**
 * 参考：https://blog.csdn.net/qq_40416052/article/details/82493916
 *
 * 用于动态申请内存，申请的是堆内存;
 * 
 * new和malloc的区别：
 * 		1.new，delete关键字是c++的一部分，不是函数； malloc是由c库提供的函数
 * 		2.new以具体类型为单位进行内存分配，malloc是以字节为单位进行内存分配
 * 		3.new在申请单个变量时可以进行初始化，如string *s = new string("hello")，
 * 			malloc不具备内存初始化的特性,但calloc可以将元素初始化为0
 * 		4.new 返回具体指针类型，malloc返回void型指针
 * 		5.new 类型是安全的，而malloc不是；如int *p = new float[2]会报错,
 * 			⽽int p = malloc(2sizeof(int))编译时编译器就⽆法指出错误来
 * 		6.new⼀般分为两步：new操作和构造。new操作对应与malloc，new操作可以重载，
 * 			可以⾃定义内存分配策略，不做内存分配，甚⾄分配到⾮内存设备上，⽽malloc不⾏。
 * 		7.new调⽤构造函数，malloc不能；delete调⽤析构函数，⽽free不能。
 * 		8.malloc/free需要库⽂件stdlib.h的⽀持，new/delete则不需要！
 * 
 * 	注意事项：
 * 		delete和free被调⽤后，内存不会⽴即回收，指针也不会指向空，delete或free仅仅是告诉操作系统，
 * 		这⼀块内存被释放了，可以⽤作其他⽤途。但是由于没有᯿新对这块内存进⾏写操作，
 * 		所以内存中的变量数值并没有发⽣变化，出现野指针的情况。因此，释放完内存后，应该讲该指针指向NULL。
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("-------------------1.变量申请-------------------------\n");
	int *p = new int;
	*p = 5;
	printf("p=%#x, *p=%d\n", p, *p);

	delete p; //删除之后并未对内存重新，内存变量值未发生变化，出现野指针
	printf("p=%#x, *p=%d\n", p, *p);//不报错
	p = NULL;
	// printf("p=%#x, *p=%d\n", p, *p);//报错
	

	printf("\n-----------------2.数组申请---------------------------\n");
	p = new int[10]; //数组里存放的不是指针，是int类型数据
	for (int i = 0; i < 10; i++)
	{
		// p[i] = i;//ok;这种方法也行
		*(p + i) = i;
		printf("p+%d=%#x  %d\n", i, p + i, p[i]); //指针每次移动4个字节
	}

	delete[] p;

	printf("\n------------------3.new关键字初始化------------------------\n");
	int *pi = new int(1); //动态申请一个int，初始化为1;注意和new int[1]区别
	float *pf = new float(10);
	char *pc = new char('a');

	printf("*pi = %d\n", *pi);	 //1
	printf("*pf = %.3f\n", *pf); //10.000
	printf("*pc = %c\n", *pc);	 //a

	delete pi;
	delete pf;
	delete pc;
}
