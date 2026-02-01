#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time Complexity: O(N) — each element processed once
// Space Complexity: O(K) — store current window elements

int main() {
    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    int right = 0;
    ll currSum = 0;         // sum of current window
    queue<ll> q;            // store elements of current window
    ll prevNum = 0, nextNum = 0;
    ll ans = 0;             // XOR of window sums

    while (right < n) {
        // generate next number in sequence
        nextNum = (right == 0) ? x : (a * prevNum + b) % c;

        currSum += nextNum; // add to current window sum
        q.push(nextNum);    // add to window

        if (q.size() == k) {   // window is full
            ans ^= currSum;    // XOR window sum
            currSum -= q.front(); // remove oldest element
            q.pop();
        }

        right++;
        prevNum = nextNum;   // update previous number
    }

    cout << ans << endl;
}
