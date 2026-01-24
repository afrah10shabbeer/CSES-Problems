#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Time = O(#states × transitions × memo lookup)
//      = O(n² × 2 × log(n²))
//      = O(n² log n)
// Space = O(#states + recursion depth)
//       = O(n² + n)
//       = O(n²)

map<pair<int, int>, ll> memoMap;
bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

ll getMaxMoney(int prevEnd, int i, vector<vector<int>> &arr, int n)
{
    if (i == n) return 0;

    if (memoMap.count({prevEnd, i}))
        return memoMap[{prevEnd, i}];

    ll take = 0;
    if (arr[i][0] > prevEnd)
        take = arr[i][2] + getMaxMoney(arr[i][1], i + 1, arr, n);

    ll noTake = getMaxMoney(prevEnd, i + 1, arr, n);

    return memoMap[{prevEnd, i}] = max(take, noTake);
}

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int>> arr(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
	    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	
	sort(arr.begin(), arr.end(), comp);
	ll ans = getMaxMoney(INT_MIN, 0, arr, n);
	cout<<ans<<endl;

}
