#include <stdio.h>
#include <iostream>

using namespace std;
int main(int argc, char *arv[])
{
    printf("--------------1.三元运算符---------------\n");
    int a = 10;
    printf("a = %d\n", a);
    a = a > 1 ? a * 2 : a * 3; //三元运算符
    printf("a = %d\n", a);

    printf("\n--------------2.逗号运算符---------------\n");
    //只取右边表达式的返回值
    int b = 0;
    int ret = (b = 100, b + 3);//先执行左侧b=100,再执行右侧并将右侧执行结果返回
    cout << "ret = " << ret << ", b=" << b << endl;

    return 0;
}