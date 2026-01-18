#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per state * memo lookup time) 
// 		= O((n * x) * 2 * 1) = O(n * x)
// Space: O(space for memo + recursion depth) 
// 		= O((n * x) + (n)(in case we take all the books)) = O(n * x)

int getMaxPages(int index, int n, int x, vector<int> &h, vector<int> &s, vector<vector<int>> &memoVec)
{
    if (index == n) 
        return 0;
    if (x < 0) 
        return -1e9;
    if (memoVec[index][x] != -1)
        return memoVec[index][x];
        
    int takeCurrBook = -1e9;
    if (x >= h[index])
        takeCurrBook = s[index] + getMaxPages(index + 1, n, x - h[index], h, s, memoVec);

    int skipCurrBook = getMaxPages(index + 1, n, x, h, s, memoVec);

    return memoVec[index][x] = max(takeCurrBook, skipCurrBook);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> s[i];
    }
    
    vector<vector<int>> memoVec(n, vector<int>(x + 1, -1));
    cout << getMaxPages(0, n, x, h, s, memoVec) << "\n";
}
