#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long getDiceCombination(int n, vector<int> &memoVec)
{
    if (n < 0)
        return 0L;
    if (n == 0)
        return 1L;
    if (memoVec[n] != -1)
        return memoVec[n];
        
    long long combinationSum = 0L;
    for (int diceNum = 1; diceNum <= 6; diceNum++)
    {
        combinationSum = (combinationSum % MOD + getDiceCombination(n - diceNum, memoVec) % MOD) % MOD;
    }
    return memoVec[n] = combinationSum;
}
int main() {
	
	int n;
	cin>>n;
	
	vector<int> memoVec(n + 1, -1);
	int ans = (int)getDiceCombination(n, memoVec);
	cout<<ans<<endl;

}
