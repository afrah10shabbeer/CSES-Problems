#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// NOTE: This Recursive + memo approach causes TLE in CSES

// Time: O(#states * cost per state * memo lookup time)
//    => O((w * h) * (w + h) * 1) => O((w * h) * (w + h))
// Space: O(memo space)
//    => O(w * h)

int cutRect(int w, int h, vector<vector<int>> &memoVec)
{
    if (w == h)
        return 0;
    
    if (memoVec[w][h] != -1)
        return memoVec[w][h];
        
    int ans = INF;
    // horizontal cuts
    for (int k = 1; k < h; k++)
    {
        // make a horizontal cut at 'k'
        ans = min(ans, 1 + cutRect(w, k, memoVec) + cutRect(w, h - k, memoVec));
    }
    
    // vertical cuts
    for (int k = 1; k < w; k++)
    {
        // make a vertical cut at 'k'
        ans = min(ans, 1 + cutRect(k, h, memoVec) + cutRect(w - k, h, memoVec));
    }
    return memoVec[w][h] = ans;
}
int main() {
	
	int w, h;
	cin>>w>>h;
	
	vector<vector<int>> memoVec(w + 1, vector<int>(h + 1, -1));
	int minMoves = cutRect(w, h, memoVec);
	cout<<minMoves<<endl;

    return 0;
}
