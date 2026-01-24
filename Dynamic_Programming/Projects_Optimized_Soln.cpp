#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Comparator to sort projects by end time
bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

// Binary search to find the last project
// whose end time is strictly less than startVal
// h is the highest index we are allowed to search till
int binarySearch(vector<vector<int>> &arr, int startVal, int h)
{
    int low = 0, high = h;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If this project ends before the current one starts,
        // it is a valid candidate
        if (arr[mid][1] < startVal)
        {
            index = mid;      // store candidate
            low = mid + 1;    // try to find a larger valid index
        }
        else
        {
            high = mid - 1;
        }
    }

    // dp is 1-indexed, so return index + 1
    // if none found, return 0 (base case)
    return (index == -1) ? 0 : index + 1;
}

int main()
{
    int n;
    cin >> n;

    // arr[i] = {start, end, reward}
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // Sort projects by end time
    sort(arr.begin(), arr.end(), comp);

    // dp[i] = max reward using first i projects
    vector<ll> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        // Option 1: skip current project
        ll skipProject = dp[i - 1];

        // Option 2: take current project
        int reward = arr[i - 1][2];

        // Find last project that does not overlap
        int k = binarySearch(arr, arr[i - 1][0], i - 2);

        ll takeProject = reward + dp[k];

        // Take the best of skip or take
        dp[i] = max(skipProject, takeProject);
    }

    // Answer is max reward using all projects
    cout << dp[n] << endl;
    return 0;
}
