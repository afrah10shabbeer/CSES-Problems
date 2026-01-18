#include <bits/stdc++.h>
using namespace std;

// Coin Combinations II (order does NOT matter)
//
// Time:  O(n * x)
// Space: O(x)   (two 1D arrays: prevDp and nextDp)

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    // prevDp = dp for previous coin row
    vector<int> prevDp(x + 1, 0);

    // Base row for coin[0]
    for (int sum = 0; sum <= x; sum++) {
        prevDp[sum] = (sum % coins[0] == 0);
    }

    // Build rows 1..n-1
    for (int i = 1; i < n; i++) {
        vector<int> nextDp(x + 1, 0);
        nextDp[0] = 1;

        for (int sum = 1; sum <= x; sum++) {
            int skipCurrCoin = prevDp[sum];
            int takeCurrCoin = 0;

            if (sum >= coins[i])
                takeCurrCoin = nextDp[sum - coins[i]];  // same row

            nextDp[sum] = (skipCurrCoin + takeCurrCoin) % MOD;
        }

        prevDp = nextDp;
    }

    cout << prevDp[x] << "\n";
    return 0;
}