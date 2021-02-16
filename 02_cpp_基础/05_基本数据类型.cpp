
/* 
    布尔型	    bool
    字符型	    char
    整型	    int
    浮点型	    float
    双浮点型	double
    无类型	    void
    宽字符型	wchar_t
    其实 wchar_t 是这样来的：typedef short int wchar_t;

    char	            1 个字节	-128 到 127 或者 0 到 255
    unsigned char	    1 个字节	0 到 255
    signed char	        1 个字节	-128 到 127
    
    int	                4 个字节	-2147483648 到 2147483647
    unsigned int	    4 个字节	0 到 4294967295
    signed int  	    4 个字节	-2147483648 到 2147483647
    short int	        2 个字节	-32768 到 32767
    unsigned short int	2 个字节	0 到 65,535
    signed short int	2 个字节	-32768 到 32767
    long int	        8 个字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
    signed long int	    8 个字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
    unsigned long int	8 个字节	0 到 18,446,744,073,709,551,615
    
    float	            4 个字节	精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字)
   
    double	            8 个字节	双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字)
    long double	        16 个字节	长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。

  */
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
 
  int a = 4;
  int b = a++; // 4  先赋值，再计算

	a = 4;
	int c = ++a; // 5 先计算，再赋值
	cout << "b = a++ : " << b << endl; //4
  cout << "c = ++a : " << c << endl; //5

  bool isEqual = 5 == 4; //0 false ,非0 true
	cout << "5==4 : " << isEqual << endl;
  return 0;
}