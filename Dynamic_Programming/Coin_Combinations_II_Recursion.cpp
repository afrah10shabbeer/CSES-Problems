#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per state * memo lookup time)
//     = O((n * x) * 1 * 1) = O(n * x)
//
// Space: O(memo space + recursion stack depth)
//      = O(n * x + (n + x)) ≈ O(n * x)
//
// NOTE: Although correct, this recursive DP solution may cause TLE on CSES

const int MOD = 1e9 + 7;
int getDistinctOrders(int index, int n, int x, vector<int> &c, vector<vector<int>> &memo)
{
    if (x == 0) return 1;
    if (x < 0 || index >= n) return 0;

    if (memo[index][x] != -1) return memo[index][x];

    int takeCoin = getDistinctOrders(index, n, x - c[index], c, memo);
    int skipCoin = getDistinctOrders(index + 1, n, x, c, memo);

    return memo[index][x] = (takeCoin + skipCoin) % MOD;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> memo(n, vector<int>(x + 1, -1));
    cout << getDistinctOrders(0, n, x, c, memo) << "\n";
}
