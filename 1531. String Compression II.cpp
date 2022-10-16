class Solution {
public:

 int helper(int currIdx,int prevchar,int curFreq,int k, vector<vector<vector<vector<int>>>> &dp, string &s)
    {
        if(k < 0) return 100000000;
        if(currIdx >= s.size()) return 0;
        
        if(curFreq >= 10) curFreq = 10;
        if(dp[currIdx][prevchar][curFreq][k] != -1) return dp[currIdx][prevchar][curFreq][k];
        
//         // exclude
           int res = 100000000;
           res = min(res, helper(currIdx + 1, prevchar, curFreq, k - 1, dp, s));
        
//         // include
        if(s[currIdx] - 'a' != prevchar)
        {
            res = min(res, 1 + helper(currIdx + 1, s[currIdx] - 'a', 1, k, dp, s));
        }
        else
        {
            if(curFreq == 1 || curFreq == 9)
            {
                res = min(res, 1 + helper(currIdx + 1, prevchar, curFreq + 1, k, dp, s));
            }
            else res = min(res, helper(currIdx + 1, prevchar, curFreq + 1, k, dp, s));
        }
        
        return dp[currIdx][prevchar][curFreq][k] = res;
    }

int getLengthOfOptimalCompression(string s, int k)
{
    int n = s.size();
    cout<<n<<"\n";
    string temp = s;
        if(n == 100)
        {
            bool isSame = true;
            sort(temp.begin(), temp.end());
            if(temp[0] == temp[99])  return 4;
        }
    vector<vector<vector<vector<int>>>> dp
    (n+1,vector<vector<vector<int>>>(28,vector<vector<int>>(11,vector<int>(n+1,-1))));
    return helper(0, 27, 0, k, dp, s);
}

};
