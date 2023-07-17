/**
 * 
 * empty() 堆栈为空则返回真
 * pop() 移除栈顶元素
 * push() 在栈顶增加元素
 * size() 返回栈中元素数目
 * top() 返回栈顶元素
 * 
 * 
 */

#include<iostream>
#include <stack>

using namespace std;

int main(int argc,char* argv[]){

   
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(2);

    st.pop();//无返回值
    
    cout<<st.top()<<endl;
    
    return -1;
}