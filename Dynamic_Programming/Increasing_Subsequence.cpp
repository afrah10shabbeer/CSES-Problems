#include <bits/stdc++.h>
using namespace std;

// Time: O(n*logn)
// Space: O(To store lis) => O(n) 
// Binary search to find the index to replace
int binarySearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// Function to compute length of LIS
int lengthOfLIS(vector<int>& nums)
{
    vector<int> lis;

    for (int x : nums)
    {
        if (lis.empty() || lis.back() < x)
            lis.push_back(x);
        else
        {
            int replaceIndex = binarySearch(lis, x);
            lis[replaceIndex] = x;
        }
    }
    return lis.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << lengthOfLIS(nums) << endl;

    return 0;
}
