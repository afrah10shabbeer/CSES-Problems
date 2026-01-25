#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

ll dp[MAX][2];

// Time: O(N * 2)
// Space: O(N * 2)
int main() {
	
    //                                                              _  _
    // dp[i][0] = ith block are two separate blocks width of 1 x 1 | || |
    //                                                  _ _
    // dp[i][1] = ith block is combined width of 2 x 1 |   |
    
    // transition:
    //                   _  _    _  _    _  _    _  _     _ _
    //       _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    // ith  | || | =>   | || |, | || |, | || |, | || |,  | | |
    //                  _ _    _ _    _ _ 
    //      _ _        |   |  |_|_|  |_ _|
    // ith |   |  =>   |   |, |   |, |   |

    // dp[i][0] = dp[i-1][0] * 4 + dp[i-1][1]
    // dp[i][1] = dp[i-1][0] + dp[i-1][1] * 2

    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        dp[i][0] = ((4 * dp[i - 1][0]) % MOD + dp[i - 1][1]) % MOD;
        dp[i][1] = ((dp[i - 1][0]) % MOD + 2 * dp[i - 1][1]) % MOD; 
    }

    int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;

        cout<<(dp[n][0] + dp[n][1]) % MOD<<endl;
	}
    return 0;
}
