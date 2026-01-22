#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// Time: O(n^2)
// Space: O(n^2)
int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
	    cin>>nums[i];
	}
	
	ll totSum = accumulate(nums.begin(), nums.end(), 0L);
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
	    dp[i][i] = nums[i];
	}
	for (int l = n - 2; l >= 0; l--)
	{
	    for (int r = 1; r < n; r++)
	    {
	       if (l > r)
	           continue;
	       ll playerTakesFirstNum = nums[l] - dp[l + 1][r];
	       ll playerTakesSecondNum = nums[r] - dp[l][r - 1];
	       
	       dp[l][r] = max(playerTakesFirstNum, playerTakesSecondNum);
	    }
	}
	
	ll maxSum = dp[0][n - 1];
	ll player1Score = (maxSum + totSum) / 2;
	cout<<player1Score<<endl;
    return 0;
}