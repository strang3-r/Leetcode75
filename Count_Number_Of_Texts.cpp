class Solution {
public:
    int countTexts(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i];
            if (i > 0 and s[i] == s[i - 1])
            {
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
                if (i > 1 and s[i] == s[i - 2])
                {
                    dp[i + 1] = (dp[i + 1] + dp[i - 2]) % mod;
                    if (i > 2 and s[i] == s[i - 3] and (s[i] == '7' or s[i] == '9'))
                        dp[i + 1] = (dp[i + 1] + dp[i - 3]) % mod;
                }
            }
        }
        return dp[n];
    }
};
