#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per state * memo lookup time) = O(x * n * 1) = O(n * x)
// Space: O(space for memo + recursion depth (worst case when coin 1 exists)) = O(x + x) = O(x)

const int INF = 1e9;
int getMinimalCoins(int n, int x, vector<int> &coins, vector<int> &memoVector)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INF;
    
    if (memoVector[x] != -1)
        return memoVector[x];
        
    int minCoins = INF;
    for (int index = 0; index < n; index++)
    {
        int coinsUsed = (1 + getMinimalCoins(n, x - coins[index], coins, memoVector));
        minCoins = min(minCoins, coinsUsed);
    }
    return memoVector[x] = minCoins;
}
int main() {
	
	int n, x;
	cin>>n>>x;
	
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
	    cin>>coins[i];
	} 
	
	vector<int> memoVector(x + 1, -1);
    int ans = getMinimalCoins(n, x, coins, memoVector);
    if (ans >= INF)
        cout<<"-1\n";
    else
        cout<<ans<<endl;

}
