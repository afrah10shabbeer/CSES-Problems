#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

int main()
{
    int n, m;
    cin >> n >> m;

    // Input first sequence
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Input second sequence
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // DP table where dp[i][j] stores LCS length of a[0..i-1] and b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If elements match, extend LCS
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // Take maximum by skipping one element
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcsLen = dp[n][m]; // Length of LCS

    // Find the LCS string
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Output LCS length
    cout << lcsLen << endl;

    // Output LCS sequence
    reverse(lcs.begin(), lcs.end());
    for (int &x : lcs)
    {
        cout << x << " ";
    }

    return 0;
}
