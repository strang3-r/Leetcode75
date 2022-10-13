/*
C++ Solution | DP | O (n)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int x = 0, y = 0, z = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min({2 * dp[x], 3 * dp[y], 5 * dp[z]});
            x += (dp[i] == 2 * dp[x]);
            y += (dp[i] == 3 * dp[y]);
            z += (dp[i] == 5 * dp[z]);
        }
        return dp[n - 1];
    }
};
