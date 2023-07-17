/**
 * 无序(hash)容器
 * 
 */

#include <iostream>
#include <unordered_set>
using namespace std;

//遍历
void traversal(unordered_set<int> &uset)
{
    for (auto iter = uset.begin(); iter != uset.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    unordered_set<int> uset;

    cout << "-----------1.插入---------" << endl;
    uset.insert(1);
    uset.insert(2);

    cout << "-----------2.遍历---------" << endl;
    traversal(uset);

    cout << "-----------3.是否包含某元素---------" << endl;
    cout << "1? : " << uset.count(1) << endl; //1
    cout << "9? : " << uset.count(9) << endl; //0

    cout << "-----------4.删除指定元素---------" << endl;
    cout << "删除前:";
    traversal(uset);

    uset.erase(1);

    cout << "删除后:";
    traversal(uset);

    cout << "-----------5.size()---------" << endl;
    cout << "size: " << uset.size() << endl;

    cout << "-----------6.clear()---------" << endl;
    uset.clear();
    cout << "size: " << uset.size() << endl;
    return -1;
}
