/*
You are given a number str(in string format) in hexadecimal. A new number can be made from the number str by selecting any subsequence of it (in HexaDecimal) and rearranging it.
You have tell the number of distinct numbers that can be made from number n.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int countOfDistinctNo(string str){
    // Code here
    int n = str.length() ;
    long long int dp[n+1] , hash[256] ;
    vector<vector<int>>dp_aux(n+1 , vector<int>(n+1 , 0));
    memset(dp , 0 , sizeof(dp));
    memset(hash , 0 , sizeof(hash));
 
    
    long long int mod = 1000000007;
    
    
    for(int i=0;i<=n;i++){
        
        for(int j=0;j<=i;j++){
            
            if(j == 0 || j == i) dp_aux[i][j] = 1;
            
            else if(j == 1) dp_aux[i][j] = i;
            else dp_aux[i][j] = dp_aux[i-1][j] + dp_aux[i-1][j-1];
            
            dp_aux[i][j] %= mod;
            
        }
    }
    
    
    
    
    
    dp[0] = 1;
    int zero = 0;
    
    
    for(int i=0;i<n;i++){
        if(str[i] != '0') hash[str[i]]++;
        else zero++;
    }
    
    
    for(int i=0;i<256;i++){
        
        if(hash[i] == 0) continue;
        
        int freq = hash[i];
        for(int k=n;k>=0;k--){
            
            for(int j=1;j<=freq;j++){
                
                
                if(k-j < 0) break;
                dp[k] += (dp[k-j]* 1LL * dp_aux[k][k-j]) % mod;
                dp[k] %= mod;
                
            }
        }
    }
 
    
    for(int k=n;k>=0;k--){
        
        for(int j=1;j<=zero;j++){
            
            if(k-j <= 0) break;
            
            dp[k] += (dp[k-j] * 1LL * dp_aux[k-1][k-j-1]) % mod;
            dp[k] %= mod;
        }
    }
    
    if(zero) dp[1]++;
    
    long long int sum = 0;
    for(int i=1;i<=n;i++){
        
        sum += dp[i];
        sum %= mod;
    }
    
    return sum;
}
};
int main(){
int t;
cin>>t;
while(t--){
string s;
cin>>s;
Solution a;
cout<<a.countOfDistinctNo(s)<<endl;
}
return 0;}
