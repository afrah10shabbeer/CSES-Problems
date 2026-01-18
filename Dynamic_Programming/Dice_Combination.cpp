#include <bits/stdc++.h>
using namespace std;
// Time: O(#states * cost per state * memo lookup time)
//      = O(n * 6 * 1) = O(n)
//
// Space: O(memo space + recursion stack depth)
//       = O(n + n) = O(n)

const int MOD = 1e9 + 7;
long long getDiceCombination(int n, vector<int> &memoVector)
{
    if (n < 0)
        return 0L;
    if (n == 0)
        return 1L;
    if (memoVector[n] != -1)
        return memoVector[n];
        
    long long combinationSum = 0L;
    for (int diceNum = 1; diceNum <= 6; diceNum++)
    {
        combinationSum = (combinationSum % MOD + getDiceCombination(n - diceNum, memoVector) % MOD) % MOD;
    }
    return memoVector[n] = combinationSum;
}
int main() {
	
	int n;
	cin>>n;
	
	vector<int> memoVec(n + 1, -1);
	int ans = (int)getDiceCombination(n, memoVec);
	cout<<ans<<endl;

}
