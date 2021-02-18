//必须是"C"不能是'C'
//使用extern "C"后,编译后的函数名就是C风格的,即不在函数名前加__
//使用g++ -S add.cpp 编译,然后查看add.s即可知
extern "C" int add(int x,int y);
