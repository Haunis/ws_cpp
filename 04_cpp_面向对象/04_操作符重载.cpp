/**
 *  操作符重载：
 *  	class默认重载了= 操作符，此操作符的含义：将=右边对象的所有非静态数据成员赋值给=左边
 * 
 * 	值传递调用函数传递对象时,会默认调用对象的拷贝构造函数
 *
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Vector
{
public:
	int x, y;
	static int array[2][2];

public:
	Vector();//空构造
	Vector(int x, int y); //构造函数，需要在其他地方初始化
	Vector(const Vector &in);//拷贝构造函数;注意将in的值赋给新对象,否则函数值传递调复制产生的新对象属性值为默认值
	~Vector(); //析构函数
public:
	Vector operator +(Vector); //重载 "+"操作符
	Vector operator *(Vector); //重载 * 操作符
	string toString();
};

int main()
{
	Vector v1(1, 1);
	Vector v2(2, 2);
	Vector v3;
	Vector v4;
	
	printf("sizeof(v4):%d\n", sizeof(v4)); //8;两个int

	printf("\n----------------v1+v2-------------\n");
	v3 = v1 + v2;
	printf("v3: %s\n",v3.toString().data());

	printf("\n----------------v1*v2-------------\n");
	v4 = v1 * v2;
	printf("v4: %s\n\n",v4.toString().data());


	//	int (*cp)[3]= Vector::array;
	//	cout << "temp_array" << temp_array[01][1] << endl;
	return 0;
}

Vector::Vector()//空构造
{ 
	x = 0, y = 0;
	// p_x = &x, p_y = &y;
	printf("空构造 this=%#x\n",this);
}
Vector::Vector(int x, int y)//有参构造
{ 
	this->x = x;
	this->y = y;
	printf("有参构造 this=%#x, x=%d,y=%d\n", this, x, y);
}
Vector::Vector(const Vector &in)//拷贝构造;注意赋值,否则值传递复制后的对象的值为默认值
{ 
	this->x = in.x;
	this->y = in.y;
	printf("拷贝构造函数: in=%#x,this=%#x\n", &in, this);
}
Vector::~Vector()
{
	cout << "析构函数 -Vector():  " << this << endl;
}

Vector Vector::operator +(Vector vector)//会调用拷贝构造函数,创建一个新对象vector接收调用对象v1的值
{
	Vector temp; //temp调用无参构造进行初始化
	temp.x = x + vector.x;
	temp.y = y + vector.y;
	printf("operation+ ,vertor=%#x, temp=%#x\n", &vector, &temp);
	return temp;
}

Vector Vector::operator *(Vector vector)
{
	Vector temp;
	temp.x = x * vector.x;
	temp.y = y * vector.y;
	printf("operation* ,vertor=%#x, temp=%#x\n", &vector, &temp);
	return temp;
}

string Vector::toString()
{
	long int address = reinterpret_cast<long int>(this); //将指针强制转化成long int
	char hex_address[20];
	sprintf(hex_address,"%#x",address);//字符串化操作
	string temp = hex_address; //使用char[] 和string直接+会报错,先将char[]转化成string
	return "this=" + temp + ",x=" + std::to_string(x) + ",y=" + /*std::*/ to_string(y);
}
