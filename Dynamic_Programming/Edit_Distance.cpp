#include <bits/stdc++.h>
using namespace std;
 
// Time: O(#states * cost per state * memo cost)
//    => O((len1 * len2) * 3 * 1) => O(len1 * len2)
// Space: O(memo size + recursion stack depth)
//    =>  O((len1 * len2) + max(len1, len2))
 
int getMinOps(int i, int j, string &s1, string &s2, vector<vector<int>> &memoVec)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (memoVec[i][j] != -1)
        return memoVec[i][j];
        
    if (s1[i] == s2[j])
        return getMinOps(i - 1, j - 1, s1, s2, memoVec);
    else
    {
        int replaceChar = getMinOps(i - 1, j - 1, s1, s2, memoVec);
        int removeChar = getMinOps(i - 1, j, s1, s2, memoVec);
        int insertChar = getMinOps(i, j - 1, s1, s2, memoVec);
        
        return memoVec[i][j] = 1 + min({replaceChar, removeChar, insertChar});
    }
}
int main() {
	
	string s1, s2;
	cin>>s1>>s2;
	
	int m = s1.size();
	int n = s2.size();
	
	vector<vector<int>> memoVec(m, vector<int>(n, -1));
	int ans = getMinOps(m - 1, n - 1, s1, s2, memoVec);
	cout<<ans<<endl;
 
}