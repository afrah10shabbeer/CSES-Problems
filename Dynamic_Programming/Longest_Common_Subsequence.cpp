#include <bits/stdc++.h>
using namespace std;
 
// Time: O(dp traversal time + (time to find lcs))
//    => O(m * n + (m + n))
// Space: O(dp size)
//    => O(m * n)
int main() {
	
	int n, m;
	cin>>n>>m;
	
	vector<int> a(n), b(m);
	
	for(int i = 0; i < n; i++)
	{
	    cin>>a[i];
	}
	
	for (int i = 0; i < m; i++)
	{
	    cin>>b[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
	    for (int j = 1; j <= m; j++)
	    {
	        if (a[i - 1] == b[j - 1])
	        {
	            dp[i][j] = 1 + dp[i - 1][j - 1];
	        }
	        else
	        {
	            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	        }
	    }
	}
	
	int lcsLen = dp[n][m];
	vector<int> lcs;
	int i = n;
	int j = m;
	while (i > 0 and j > 0)
	{
	    if (a[i - 1] == b[j - 1])
	    {
	        lcs.push_back(a[i - 1]);
	        i--;
	        j--;
	    }
	    else if (dp[i - 1][j] >= dp[i][j - 1])
	        i--;
	   else
	        j--;
	}
	cout<<lcsLen<<endl;
	reverse(lcs.begin(), lcs.end());
	for (int &x: lcs)
	{
	    cout<<x<<" ";
	}
	
	return 0;
}