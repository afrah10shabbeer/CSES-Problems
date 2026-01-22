#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Time: O(n * targetSum) => O(n * (n * (n + 1) / 4)) => O(n^3)
// Space: O(n * targetSum) + O(n) recursion stack => O(n^3)

int getSubsetSum(ll num, ll targetSum, int n, vector<vector<ll>> &memoVec)
{
    // If sum becomes negative or numbers are exhausted
    if (targetSum < 0 || num > n)
        return 0;

    // If required sum is achieved
    if (targetSum == 0)
        return 1;

    // If already computed, return stored result
    if (memoVec[num][targetSum] != -1)
        return memoVec[num][targetSum];

    // Take the current number
    ll takeNum = getSubsetSum(num + 1, targetSum - num, n, memoVec);

    // Skip the current number
    ll skipNum = getSubsetSum(num + 1, targetSum, n, memoVec);

    // Store and return the result
    return memoVec[num][targetSum] = (takeNum + skipNum) % MOD;
}

int main() {
    int n;
    cin >> n;

    // Total sum of numbers from 1 to n
    ll totSum = (n * (n + 1)) / 2;

    // If total sum is odd, partition is impossible
    if (totSum % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }

    // Target sum for each subset
    ll targetSum = totSum / 2;

    // Memoization table
    vector<vector<ll>> memoVec(n + 1, vector<ll>(targetSum + 1, -1));

    // Count number of subsets with sum = targetSum
    int ans = getSubsetSum(1, targetSum, n, memoVec);

    cout << ans << endl;
    return 0;
}
