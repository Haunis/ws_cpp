#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <limits.h> //INT_MAX

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
    }
    //合并有序数组,找出中位数
    double findValue1(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0, total_len = nums1.size() + nums2.size();
        vector<int> new_vec;
        while (index1 < nums1.size() || index2 < nums2.size())
        {
            int leftValue = INT_MAX, rightValue = INT_MAX;
            if (index1 < nums1.size()) leftValue = nums1[index1];
            if (index2 < nums2.size()) rightValue = nums2[index2];
            
            if (leftValue <= rightValue)
            {
                new_vec.push_back(leftValue);
                index1++;
            }
            else
            {
                new_vec.push_back(rightValue);
                index2++;
            }
        }

        return (double)(new_vec[(total_len - 1)/2] + new_vec[total_len/2]) / 2;
    }
};
int main(int argc, char *argv[])
{
    int arr1[] = {2, 3};
    vector<int> v1(arr1, arr1 + 2);

    int arr2[] = {4, 5};
    vector<int> v2(arr2, arr2 + 2);

    Solution s;

    double ret = s.findValue1(v1, v2);
    cout << "ret=" << ret << endl;

    return 0;
}