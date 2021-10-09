#include <vector>
#include <iostream>
// #include <ctime>
#include <sys/time.h> //timeval

#define RANDOM(a, b) (rand() % (b - a) + a) //[a,b)

using namespace std;

int64_t getMilliSecond() //毫秒
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d\t", vec[i]);
        if (i != 0 && i % 30 == 0)
            printf("\n");
    }
    printf("\n");
}

//快排
void quickSort(vector<int> &vec, int start, int end)
{
    if (start >= end)
        return;

    int left = start + 1, right = end;
    while (left < right)
    {
        while (left < right && vec[left] <= vec[start])
        {
            left++;
        }
        while (left < right && vec[right] > vec[start])
        {
            right--;
        }
        swap(vec[left], vec[right]);
    }
    if (vec[start] < vec[left])
    {
        left--;
    }

    swap(vec[start], vec[left]);
    quickSort(vec, start, left - 1);
    quickSort(vec, left + 1, end);
}

//希尔排序
void shellSort(vector<int> &nums)
{
    int gap = nums.size() / 2;
    while (gap >= 1)
    {
        for (int i = gap; i < nums.size(); i++)
        {
            for (int j = i; j > 0; j = j - gap)
            {
                if (j - gap >= 0 && nums[j] < nums[j - gap])
                {
                    swap(nums[j], nums[j - gap]);
                }
                else
                {
                    break;
                }
            }
        }
        gap /= 2;
    }
}

void adjustHeap(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        int k = 2 * start + 1;
        if (k > end)
            return;
        if (k + 1 <= end && nums[k] < nums[k + 1])
            k++;
        if (nums[start] < nums[k])
        {
            swap(nums[start], nums[k]);
            start = k;
        }
        else
        { //别忘记退出
            break;
        }
    }
}

//堆排序
void heapSort(vector<int> &nums)
{
    for (int i = nums.size() / 2 - 1; i >= 0; i--) //建立大顶堆
    {
        adjustHeap(nums, i, nums.size() - 1);
    }
    for (int i = nums.size() - 1; i > 0; i--)
    {
        adjustHeap(nums, 0, i);
        swap(nums[0], nums[i]);
    }
}

int main(int arg, char *argv[])
{
    vector<int> nums = {4, 2, 3, 1, 18, 9};

    nums.clear();
    for (int i = 0; i < 10000; i++)
        nums.push_back(RANDOM(10, 20));

    int64_t start = getMilliSecond();
    // quickSort(nums, 0, nums.size() - 1);
    // shellSort(nums);
    heapSort(nums);

    printVec(nums);

    int64_t end = getMilliSecond();
    cout << endl;
    cout << "time: " << float(end - start) / 1000 << endl;
    return -1;
}