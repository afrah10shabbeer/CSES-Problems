#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per state * memo lookup time)
//     = O(n * (number of digits in n) * 1)
//     = O(n * log10(n))
//
// Space: O(memo space + recursion stack depth)
//      = O(n + n(for small digit reductions)) = O(n)

int getMinSteps(int n, vector<int> &memoVec)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return 1e9;
      
    if (memoVec[n] != -1)
        return memoVec[n];
        
    int num = n;
    int minSteps = 1e9;
    while(num > 0)
    {
        int last_digit = num % 10;
        if (last_digit != 0)
        {
            int totSteps = 1 + getMinSteps(n - last_digit, memoVec);
            minSteps = min(minSteps, totSteps);
        }
        num = num / 10;
    }
    return memoVec[n] = minSteps;
}
int main() {
	int n;
	cin>>n;
	
	vector<int> memoVec(n + 1, -1);
	int ans = getMinSteps(n, memoVec);
    cout<<ans<<endl;
}
