#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * memo lookup time) 
// 		= O((n * x) * 1) = O(n * x)
// Space: O(space for memo) 
// 		= O((n * x)) = O(n * x)

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> s[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    
    // set first row 
    for (int j = 1; j <= x; j++)
    {
        int firstBookCost = h[0];
        if (j >= firstBookCost)
            dp[0][j] = s[0];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int money = 0; money <= x; money++)
        {
            int takeBook = 0;
            if (money >= h[i])
                takeBook = s[i] + dp[i - 1][money - h[i]];
                
            int skipBook = dp[i - 1][money];
            
            dp[i][money] = max(takeBook, skipBook);
        }
    }
    
    cout << dp[n - 1][x] << "\n";
}
