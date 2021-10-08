/**
 * isalpha(char c): 是否是字母
 * isalnum(char c): 是否是0或者字母
 * islower(char c): 是否是小写字母
 * isupper(char c): 是否是大写字母
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
    cout << typeid(s[s[0]]).name() << endl; //c, char类型
    cout << s[4] << endl; //某个位置的字符
    

    cout << "-------------3.isalnum()------------" << endl;
    cout << isalnum(',') << endl; //0

    cout << "-------------4.islower()------------" << endl;
    cout << islower('a') << endl; // 非0
    cout << isupper('a') << endl; // 0

    cout << "-------------5.substr------------" << endl;
    //substr(size_type __pos = 0, size_type __n = npos),第二个参数表示长度
    //注意和Java里substring(beginIndex,endIndex)参数含义不一样
    cout<<s.substr(1,2)<<endl; 

    cout << "-------------6.比较string------------" << endl;
    string temp = "hello"; //比较两个string直接用 "=="即可
    cout << (s==temp) << endl;
    return -1;
}