class Solution {
public:
    bool isMatch(string a, string b) {
         int n=a.size(),m=b.size();
    bool dp[n+1][m+1];
    memset(dp,false,sizeof(dp));
    if(m==0)
    return n==0;
    
  dp[0][0]=true;
  for(int i=1;i<=m;i++)
    if(b[i-1]=='*')
    dp[0][i]=dp[0][i-1];
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[j-1]=='?' || b[j-1]==a[i-1])
            dp[i][j]=dp[i-1][j-1];
            else if(b[j-1]=='*')
            dp[i][j]=dp[i-1][j] || dp[i][j-1];
            else if(b[j-1]!=a[i-1])
            dp[i][j]=false;
        }
    }
    if(dp[n][m])
    return 1;
    return 0;
        
    }
};