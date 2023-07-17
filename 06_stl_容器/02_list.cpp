/**
 * @date 2023-07-16
 *
 * 参考：
 *  https://blog.csdn.net/qq_56663697/article/details/121308759
 *  https://blog.csdn.net/qq_43448856/article/details/123916550
 *  https://blog.csdn.net/qq207713/article/details/108940856
 *
 * 1. 原理
 *      底层是双链表结构，不支持随机访问
 *
 *
 * 2.常用方法
 *      front(): 返回第一个元素
 *      back(): 返回最末元素
 *      push_front(e):头部插入一个元素
 *      pop_front(): 头部删除一个元素
 *      l1.~list(): 销毁所有元素释放内存
 *      clear(): 清空所有元素
 *
 *
 */
#include <iterator>
#include <list>
#include <iostream>
#include <algorithm> //std::find()

using namespace std;

template <typename T>
void printList(list<T> &l)
{
    for (auto e : l)
    {
        cout << e << " ";
    }
    // printf("\n");
    cout << endl;
}

bool cmp(int &i1, int &i2)
{
    return i1 < i2; // 升序
}

int main()
{
    list<int>::iterator it; // 定义一个迭代器指针

    printf("\n---------------1.构造-------------------\n");
    // list<int> l1;	// ok; 构造int类型的空容器
    list<int> l1 = {1, 2, 3};
    list<int> l2(3, 2); // 构造含有3个2的int类型容器
    list<int> l3(l2);   // 拷贝构造

    string s("hello");
    list<char> l4(s.begin(), s.end()); // 利用迭代器构造

    printList(l1);
    printList(l2);
    printList(l3);
    printList(l4);

    printf("\n---------------2.push_front:头部插入元素-------------------\n");
    l1.push_front(10);
    printList(l1);

    printf("\n---------------3.push_back:尾部插入元素-------------------\n");
    l1.push_back(10);
    printList(l1);

    printf("\n---------------4.insert:指定位置插入元素-------------------\n");
    printf("在元素 10 的位置插入 18 ...\n");
    it = find(l1.begin(), l1.end(), 10); // 找到元素10的位置
    l1.insert(it, 18);                   // 在该位置插入新元素
    printList(l1);

    printf("\n在pos=1插入 28 ...\n");
    it = l1.begin();
    it++;
    l1.insert(it, 28);
    printList(l1);

    printf("\n---------------5.pop_back:尾部弹出一个元素-------------------\n");
    l1.pop_back(); // 尾部删除一个元素无返回值
    printList(l1);

    printf("\n---------------6.查找元素-------------------\n");
    it = std::find(l1.begin(), l1.end(), 28);
    if (it == l1.end())
    {
        printf("无元素28\n");
    }
    else
    {
        int index = std::distance(l1.begin(), it);
        printf("元素 28 索引:%d\n", index);
    }

    printf("\n---------------7.1 erase:删除指定位置元素-------------------\n");
    printList(l1);

    printf("\n删除元素2: \n");
    it = find(l1.begin(), l2.end(), 2); // 找到第一次出现 2 的位置
    l1.erase(it);
    printList(l1);

    printf("\n---------------7.2 remove:删除所有值为指定值的元素-------------------\n");
    l1.remove(18); // 删除所有值为18的元素
    printList(l1);

    printf("\n---------------8.front:返回第一个元素引用-------------------\n");
    // int front = nums.front();//ok;但不是常规用法
    int &front = l1.front(); // 返回第一个元素的引用;改变front的值会更改nums中的值
    printf("front类型 --> %s\n", typeid(front).name());
    front = front * 10;
    printList(l1);

    printf("\n---------------9.assign:赋值-------------------\n");
    list<int> temp = {11, 22, 33};
    l1.assign(temp.begin(), temp.end()); // 将temp所有元素全部赋值给l1
    printList(l1);

    printf("\n---------------9.遍历-------------------\n");
    // for(int item: l1)
    for (auto item : l1)
    {
        cout << item << " ";
    }
    cout << endl;

    it = l1.begin();
    while (it != l1.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    printf("\n---------------10.排序-------------------\n");
    cout << "排序前" << endl;
    list<int> l = {8, 9, 4, 1, 12, 7, 3};
    printList(l);

    // sort(l.begin(), l.end());
    l.sort(cmp);

    cout << "排序后" << endl;
    printList(l);

    return 0;
}