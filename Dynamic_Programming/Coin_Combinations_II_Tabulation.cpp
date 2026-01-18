#include <bits/stdc++.h>
using namespace std;

// Coin Combinations II (order does NOT matter)
//
// dp[i][sum] = number of ways to make sum 'sum' using coins[0..i]
// Transition:
//   skip coin i  -> dp[i-1][sum]
//   take coin i  -> dp[i][sum - coin[i]]  (unlimited supply, stay in same row)
//
// Time:  O(n * x)
// Space: O(n * x)

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Base case: sum = 0 can always be formed in exactly 1 way (choose nothing)
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    // Base row: using only the first coin, we can form sums divisible by coins[0]
    for (int sum = 0; sum <= x; sum++) {
        dp[0][sum] = (sum % coins[0] == 0);
    }

    // Fill dp table
    for (int i = 1; i < n; i++) {
        for (int sum = 1; sum <= x; sum++) {

            int skipCurrCoin = dp[i - 1][sum];
            // "I'm not helping :(" -> ways without using coin i

            // "I'll contribute :)" -> take coin i once, and form remaining sum (unlimited use)
            int takeCurrCoin = 0;
            if (sum >= coins[i])
                takeCurrCoin = dp[i][sum - coins[i]];
            
            dp[i][sum] = (skipCurrCoin + takeCurrCoin) % MOD;
        }
    }

    cout << dp[n - 1][x] << "\n";
    return 0;
}
