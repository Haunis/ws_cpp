/*
 * 
 * https://www.cnblogs.com/jw-zhao/p/14697939.html
 * 
 * sort对数组进行排序时
 *      sort(arr+2,arr+4)， 是对索引[2,4)上的元素进行排序
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        printf("%d\t", vec[i]);

    printf("\n");
}

//当数组作为函数的参数进行传递时，该数组自动退化为同类型的指针。
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", *(array + i));

    printf("\n");
}

int main(int argc, char *argv[])
{
    int arr[] = {4, 8, 12, 7, 1, 4};
    cout << "排序前" << endl;
    printArray(arr, sizeof(arr) / sizeof(int));
    cout << "排序后" << endl;
    sort(arr, arr + 6);//arr[0]~arr[5]
    printArray(arr, sizeof(arr) / sizeof(int));

    cout<<endl;

    vector<int> nums = {4, 8, 12, 7, 1, 4};
    cout << "排序前" << endl;
    printVec(nums);
    cout << "排序后" << endl;
    sort(nums.begin(), nums.end());
    printVec(nums);
    return -1;
}
