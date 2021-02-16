/*
 *  Created on: 2019年3月11日
 *      Author: BTI-PC
 *
 *		typeid(exepression)
 *		检查一个表达式的类型，返回一个类型为type_info的常量对象指针
 */
#include <iostream>
#include <typeinfo>
using namespace std;

class Student
{
};
int main()
{
	Student **pp_stu, *p_stu, stu;
	int x = 1;
	int *int_p = &x;

	char *char_p;
	const char *const_char_p;

	char char_arr[] = "hhh";
	int int_arr[] = {1, 2, 3};

	int two_dim_arr[3][2] = {{1, 2}, {3, 4}, {5, 6}}; //二维数组
	int(*arr_p)[2] = two_dim_arr;					  //数组指针，行指针,本质上还是个一级指针
	int aa = 1, bb = 2;
	int *p_arr[2] = {&aa, &bb}; //指针数组

	printf("整型 x --> %s\n", typeid(x).name());			 //i
	printf("整型指针 int_p --> %s\n", typeid(int_p).name()); //pi

	printf("字符指针 char_p --> %s\n", typeid(char_p).name());			   //pc； point char
	printf("常量指针 const_char_p --> %s\n", typeid(const_char_p).name()); //PKc

	printf("字符数组 char_arr --> %s\n", typeid(char_arr).name()); //A4_c ,array_c
	printf("int数组 int_arr --> %s\n", typeid(int_arr).name());	   //A3_i; array_i

	printf("二维数组 two_dim_arr --> %s\n", typeid(two_dim_arr).name()); //A3_A2_i
	printf("int数组 arr_p --> %s\n", typeid(arr_p).name());				 //PA2_i
	printf("指针数组 p_arr --> %s\n", typeid(p_arr).name());			 //A2_Pi

	if (typeid(p_stu) != typeid(stu))
	{
		cout << "p_stu and stu 类型不同 " << endl;
	}
	cout << "typeid(p_stu)-->" << typeid(typeid(p_stu)).name() << endl; //N10__cxxabiv119__pointer_type_infoE
	cout << "typeid(stu)-->" << typeid(typeid(stu)).name() << endl;		//N10__cxxabiv117__class_type_infoE
	cout << "对象二级指针 p_stu -->" << typeid(pp_stu).name() << endl;//PP7Student
	cout << "对象指针 p_stu -->" << typeid(p_stu).name() << endl;//P7Student
	cout << "对象 stu -->" << typeid(stu).name() << endl;	//7Student
	cout << "Student -->" << typeid(Student).name() << endl;//7Student

	return 0;
}
