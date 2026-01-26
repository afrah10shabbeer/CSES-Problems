#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * transitions_per_state * memo_lookup)
//      ≈ O((cols * 2^rows) * (3^rows) * 1)
//
// Space: O(cols * 2^rows)
//        (DP table + recursion stack)

typedef long long ll;
const int MOD = 1e9 + 7;

int rows, cols;
ll dp[1005][(1 << 12)];   // dp[col][mask]

// check if bit k is set in mask
bool isBitSet(ll mask, int k) 
{
    return (mask & (1LL << k)) != 0;
}

// generate all valid next column masks
void generateNextMask(int i, int col, ll currMask, ll nextMask, vector<ll> &nextMasks) 
{
    if (i == rows) 
    {
        nextMasks.push_back(nextMask);
        return;
    }

    // already filled cell
    if (isBitSet(currMask, i)) 
    {
        generateNextMask(i + 1, col, currMask, nextMask, nextMasks);
        return;
    }

    // vertical domino
    if (i + 1 < rows && !isBitSet(currMask, i + 1)) 
    {
        generateNextMask(i + 2, col, currMask, nextMask, nextMasks);
    }

    // horizontal domino
    if (col + 1 < cols) 
    {
        generateNextMask(i + 1, col, currMask, nextMask | (1LL << i), nextMasks);
    }
}

// DP over columns
ll placeTiles(int col, ll mask) 
{
    // base case: processed all columns
    // valid tiling only if no cell spills out
    if (col == cols)
        return (mask == 0);

    // memoized result
    if (dp[col][mask] != -1)
        return dp[col][mask];

    ll ans = 0;

    // store all possible masks for next column
    vector<ll> nextMasks;

    // generate valid next-column masks
    generateNextMask(0, col, mask, 0LL, nextMasks);

    // try all transitions
    for (ll nextMask : nextMasks) 
    {
        ans = (ans + placeTiles(col + 1, nextMask)) % MOD;
    }

    // save and return result
    return dp[col][mask] = ans;
}


int main() 
{
    cin >> rows >> cols;
    memset(dp, -1, sizeof(dp));

    cout << placeTiles(0, 0LL) << "\n";
    return 0;
}
