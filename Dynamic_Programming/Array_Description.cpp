#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MOD = 1e9 + 7; 
 
// Time: O(Time to fill dp table) => O(n * m)
// Space: O(dp table size) => O(n * m)
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
 
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));
 
    // Base case: initialize DP for the first index
    if (nums[0] == 0) 
    {
        // If the first element is unknown, it can take any value from 1 to m
        for (int val = 1; val <= m; val++)
        {
            dp[0][val] = 1L;
        }
    }
    else
    {
        // If the first element is fixed, there is exactly one way to place it
        // that num itself
        dp[0][nums[0]] = 1L;
    }
 
    // Fill DP table for indices from 1 to n-1
    for (int i = 1; i < n; i++)
    {
            if (nums[i] == 0)
            {
                for (int val = 1; val <= m; val++)
                {
                    // If the current value is unknown:
                    // Number of ways to place 'val' at index i is the sum of:
                    // ways to place (val - 1), val, or (val + 1) at index i - 1
                    dp[i][val] = (
                        dp[i - 1][val - 1] +
                        dp[i - 1][val] +
                        dp[i - 1][val + 1]
                    ) % MOD;
                }
            }
            else
            {
                // If the current value is known:
                // The number of ways to keep nums[i] at index i is the sum of:
                // ways to place (nums[i] - 1), nums[i], or (nums[i] + 1) at index i - 1
                dp[i][nums[i]] = (
                    dp[i - 1][nums[i] - 1] +
                    dp[i - 1][nums[i]] +
                    dp[i - 1][nums[i] + 1]
                ) % MOD;
            }
        
    }
 
    // Compute the final answer by summing all valid values at the last index
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (int)(ans + dp[n - 1][j]) % MOD;
    }
 
    cout << ans << "\n";
    return 0;
}