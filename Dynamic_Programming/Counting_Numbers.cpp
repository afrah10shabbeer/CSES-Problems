#include <bits/stdc++.h>
using namespace std;

// ------------------ Memoization Table ------------------
// dp[index][prevDigit][isLeadingZeros][tightDigitLimit]
// index: current position in the number (0-based)
// prevDigit: previous digit used (-1 for none, else 0-9)
// isLeadingZeros: true if all digits so far are zeros
// tightDigitLimit: true if current number prefix is equal to prefix of upper bound

int dp[20][10][2][2]; 

// Returns the number of integers <= num with no adjacent equal digits
int generateNums(string num, int index, int prevDigit, bool isLeadingZeros, bool tightDigitLimit)
{
    // Base case: processed all digits
    if (index == num.size())
        return 1;  

    // Memoization
    if (prevDigit != -1 && dp[index][prevDigit][isLeadingZeros][tightDigitLimit] != -1)
        return dp[index][prevDigit][isLeadingZeros][tightDigitLimit];
    
    // Maximum digit allowed at this position
    int upperBound = tightDigitLimit ? (num[index] - '0') : 9;

    int ans = 0;
    
    // Try all digits for current position
    for (int digit = 0; digit <= upperBound; digit++)
    {
        // Skip if same as previous digit (except for leading zeros)
        if (digit == prevDigit && !(digit == 0 && isLeadingZeros))
            continue;

        // Update flags for recursion
        bool newLeadingZeros = isLeadingZeros && (digit == 0);
        bool newTightDigitLimit = tightDigitLimit && (digit == upperBound);

        // Recur for next position
        ans += generateNums(num, index + 1, digit, newLeadingZeros, newTightDigitLimit);
    }

    if (prevDigit != -1)
        dp[index][prevDigit][isLeadingZeros][tightDigitLimit] = ans;

    return ans;
}

// Checks if a given number has no adjacent equal digits
bool isValid(string num)
{
    int n = num.size();
    for (int i = 1; i < n; i++)
        if (num[i - 1] == num[i])
            return false;
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;

    // Count numbers <= b
    memset(dp, -1, sizeof(dp));
    int count_b = generateNums(b, 0, -1, true, true);

    // Count numbers <= a
    memset(dp, -1, sizeof(dp));
    int count_a = generateNums(a, 0, -1, true, true);

    // Numbers in [a, b] = count_b - count_a
    int ans = count_b - count_a;
    if (isValid(a)) // include 'a' if valid
        ans += 1;

    cout << ans << endl;
    return 0;
}
