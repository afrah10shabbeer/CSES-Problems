#include <bits/stdc++.h>
using namespace std;
 
// Time: O(#states)
//     => O(n * totSum)
// Space: O(dp size)
//     => O(n * totSum)
int main() {
	
	int n;
	cin>>n;
	
	vector<int> coins(n);
	
	for (int i = 0; i < n; i++)
	{
	    cin>>coins[i];
	}
	
	int totSum = accumulate(coins.begin(), coins.end(), 0);
	vector<vector<bool>> dp(n, vector<bool>(totSum + 1, 0));
	
	// first column sum = 0
	for (int i = 0; i < n; i++)
	{
	    dp[i][0] = true; 
	}
	
	dp[0][coins[0]] = true;
	
	for (int i = 1; i < n; i++)
	{
	    for (int sum = 1; sum <= totSum; sum++)
	    {
	        bool skipCurrCoinSum = dp[i - 1][sum];
	        
	        bool takeCurrCoinSum = (coins[i] <= sum) ? (dp[i - 1][sum - coins[i]]) : false;
	        
	        dp[i][sum] = (skipCurrCoinSum || takeCurrCoinSum);
	    }
	}
	
    vector<int> sumArr;
	for (int sum = 1; sum <= totSum; sum++)
	{
	    if (dp[n - 1][sum] == true)
	    {
            sumArr.push_back(sum);
        }
	}
    cout<<sumArr.size()<<endl;
    for (int &x: sumArr)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
	return 0;
 
}