#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time Complexity: O(N) — each element is processed once
// Space Complexity: O(K) — stores elements of the current window

int main() {

    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    int right = 0;

    deque<ll> dq;   // monotonic deque to keep minimum of window
    queue<ll> q;    // normal queue to track window elements

    ll prevNum = 0;
    ll currNum = 0;
    ll ans = 0;

    while (right < n) {

        // generate next number in the sequence
        currNum = (right == 0) ? x : (a * prevNum + b) % c;

        // maintain increasing order in deque
        while (!dq.empty() && dq.back() > currNum)
            dq.pop_back();
        dq.push_back(currNum);

        // add element to window
        q.push(currNum);

        // when window size becomes k
        if (q.size() == k) {
            ans ^= dq.front();     // XOR the minimum of current window

            // remove element leaving the window
            if (q.front() == dq.front())
                dq.pop_front();
            q.pop();
        }

        prevNum = currNum;
        right++;
    }

    cout << ans << endl;
}
