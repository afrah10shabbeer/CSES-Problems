#include <bits/stdc++.h>
using namespace std;

// Time: O(#states * cost per state * memo lookup time) 
// 		= O((n^2) * 2 * 1) = O(n * n)
// Space: O(space for memo + recursion depth (worst case when coin 1 exists)) 
// 		= O((n^2) + (n + n)) = O(n * n)

const int MOD = 1e9 + 7;
int getTotPaths(int row, int col, int n, vector<vector<char>> &grid, vector<vector<int>> &memoVector)
{
    if (row < 0 or row >= n or col < 0 or col >= n or grid[row][col] == '*')
        return 0;
    if (row == n - 1 and col == n - 1)
        return 1;
    if (memoVector[row][col] != -1)
        return memoVector[row][col];
        
    int goDown = getTotPaths(row + 1, col, n, grid, memoVector);
    int goRight = getTotPaths(row, col + 1, n, grid, memoVector);
    
    return memoVector[row][col] = (goDown + goRight) % MOD;
}
int main() {
	int n;
	cin>>n;
	
	vector<vector<char>> grid(n, vector<char>(n, '#'));
	for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> memoVector(n, vector<int>(n, -1));
    int ans = getTotPaths(0, 0, n, grid, memoVector);
    cout<<ans<<endl;
    return 0;
}
