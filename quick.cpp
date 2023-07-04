#include <bits/stdc++.h>
using namespace std;

int random(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}

int cnt = 0;
int partition(vector<int> &nums, int start, int end) 
{
    int x = nums[end];
    int i = start - 1;
    int j;
    for (j = start; j < end; j++)
    {
        cnt++;

        if (nums[j] <= x)
        {
            
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[end]);
    return i + 1;
}

int randomized_partition(vector<int> &nums, int start, int end)
{
    int i = random(start, end);
    swap(nums[i], nums[end]);
    return partition(nums, start, end);
}

void quickSort (vector<int> &nums, int start, int end) 
{
   
    if (start < end) 
    {
        int p = randomized_partition(nums, start, end);
        quickSort(nums, start, p - 1);
        quickSort(nums, p + 1, end);
    }
}
int main() 
{
    vector<int> nums {4, 3, 6, 8, 5, 9, 20, 50, 12, 30, 432, 12, 69, 29, 40, 50, 10, 4, 23, 34, 45, 45, 24,
89, 799, 45, 80, 50, 10, 30, 43,54,65,76,87, 98, 21, 32, 43, 78, 98, 57, 29, 91, 34,
54, 64, 19, 82, 87, 65};
    // vector<int> nums {1,4,8,21,25};
    // vector<int> nums {25,21,8,4,1};
    quickSort(nums, 0, nums.size() - 1);
    cout << "Sorted Array: ";
    for (auto c: nums) 
    {
        cout << c << " ";
    }
    cout << endl << endl;
    cout << "Total Number Of Comparisons: " << cnt << endl;

    return 0;
}