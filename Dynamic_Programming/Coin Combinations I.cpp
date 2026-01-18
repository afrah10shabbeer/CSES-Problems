#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per one state * memoVector lookup time)
//     = O(x * n * 1) => O(x * n)
//
// Space: O(memoVector size + recursion stack depth(worst case when coin 1 exists))
//     = O(x + x) => O(x)

const int MOD = 1e9 + 7;
int getDistinctWays(int n, int x, vector<int> &c, vector<int> &memoVector)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;
    
    if (memoVector[x] != -1)
        return memoVector[x];
        
    int totWays = 0;
    for (int i = 0; i < n; i++)
    {
        totWays = (totWays + getDistinctWays(n, x - c[i], c, memoVector)) % MOD;
    }
    return memoVector[x] = totWays;
}
int main() {
	
	int n, x;
	cin>>n>>x;
	
	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
	    cin>>c[i];
	} 
	
	vector<int> memoVector(x + 1, -1);
    int ans = getDistinctWays(n, x, c, memoVector);
    cout<<ans<<endl;
}
