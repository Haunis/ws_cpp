/**
 * isalpha(char c): 是否是字母
 * isalnum(char c): 是否是0或者字母
 * islower(char c): 是否是小写字母
 * isupper(char c): 是否是大写字母
 *
 * 数据类型转换
 * 1.string转char*:
 *      1.string.data()
 *          const char *char_p = ss.data();
 *          char *char_p = (char *)ss.data();
 *		2.string.c_str()
 *		3.str.copy(char[],0,5)
 *		参考: https://www.cnblogs.com/wuruofeng/p/10412559.html
 *
 * 2.string转int：
 *      1.std::stoi("12");
 *      2.stringstream(string ss) >> ret
 * 		  stringstream是一个类,将string类型的变量转换成其他如int ,float类型的变量
 *
 * 3.int转string：
 *      string ss = std::to_string(12)
 * 4.char转string：
 *
 *
 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[])
{
    string s = "hello";

    cout << "-------------1. s.length()------------" << endl;
    cout << s.length() << endl;

    cout << "-------------2. s[0]------------" << endl;
    cout << typeid(s[s[0]]).name() << endl; // c, char类型
    cout << s[4] << endl;                   // 某个位置的字符

    cout << "-------------3.isalnum()------------" << endl;
    cout << isalnum(',') << endl; // 0; 是否是0或者字母

    cout << "-------------4.islower()------------" << endl;
    cout << islower('a') << endl; // true, 非0; 是否是小写
    cout << isupper('a') << endl; // false，0； 是否是大写

    cout << "//////////////////////////转换//////////////////////////" << endl;

    cout << "-------------5.1 string转char*-------------" << endl;
    string ss = "hello";
    //	const char *char_p = ss.data();//常量指针，里面内容不可修改
    char *char_p = (char *)ss.data(); // 转换后就是一个普通指针
    // const char *char_p = ss.c_str();//常量指针，里面内容不可修改
    printf("char_p=%s, sizeof(char_p)=%lu\n", char_p, sizeof(char_p)); // size是8,指针

    *char_p = 'x';                 // 不是常量指针，可以为里面的内容重新赋值
    printf("char_p=%s\n", char_p); // xello
    cout << "ss=" << ss << endl;   // xello

    cout << "\n-----------5.2 string转int-------------------" << endl;
    string ss12 = "3";
    int ret12;
    // stringstream(ss12) >> ret12;
    ret12 = std::stoi(ss12);
    printf("ret12 = %d\n", ret12);

    cout << "\n-----------5.3 int转string-------------------" << endl;
    cout << std::to_string(100) << endl;

    // string str = 9 + '0'; //error;单个数字转换成string
    string str;
    str = 9 + '0';
    cout << str << endl; // 9

    cout << "\n-----------5.4 char转string-------------------" << endl;
    char c = '1';
    string ret = "";

    ret = c; // 这个也ok??
    ret += c;
    cout << ret << endl; // 11

    cout << string(4, c) << endl; // 1111
    return -1;
}