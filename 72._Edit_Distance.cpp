// Problem Link
// https://leetcode.com/problems/edit-distance/

// Recursion based approach
class Solution {
public:
    
    int editDis(string& word1, string& word2, int n1, int n2)
    {
        if(n1 == 0)
            return n2;
        if(n2 == 0)
            return n1;
        if(word1[n1-1] == word2[n2-1]) {
            return editDis(word1, word2, n1-1, n2-1);
        }
            
        return 1+min(editDis(word1, word2, n1, n2-1),
                  min(editDis(word1, word2, n1-1, n2),
                  editDis(word1, word2, n1-1, n2-1)));
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return editDis(word1, word2, n1, n2);
        
    }
};

// DP tabulation based approach
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=m;++i)
            dp[0][i]=i;
        for(int i=0;i<=n;++i)
            dp[i][0]=i;
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
        
        return dp[n][m];
    }
};

// DP memoization based approach
class Solution {
public:
    int dp[1001][1001];
    
    int editDis(string& word1, string& word2, int n1, int n2)
    {
        if(n1 == 0)
            return n2;
        if(n2 == 0)
            return n1;

        if(dp[n1][n2] !=-1)
        {
            return dp[n1][n2];
        }

        if(word1[n1-1] == word2[n2-1]) {
            dp[n1][n2] = editDis(word1, word2, n1-1, n2-1);
            return dp[n1][n2];
        }
            
        dp[n1][n2]=  1+min(editDis(word1, word2, n1, n2-1),
                  min(editDis(word1, word2, n1-1, n2),
                  editDis(word1, word2, n1-1, n2-1)));
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        for(int i=0;i<=n1+1;i++)
        {
            for(int j=0;j<=n2+1;j++)
            {
                dp[i][j] = -1;
            }
        }

        dp[n1][n2] = editDis(word1, word2, n1, n2);
        return dp[n1][n2];
    }
};