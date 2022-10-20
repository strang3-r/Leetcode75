#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int obc=0;
        int cbc=0;
        vector<string>v;
        ans(v,n,obc,cbc,"");
        return v;
        
    }
    void ans(vector<string>&v,int n,int obc,int cbc,string s){

        if(obc==n&&(cbc==n)){

        v.push_back(s);
            return ;
        }
        
if(obc<n){
    ans(v,n,obc+1,cbc,s+"(");
}
        if(obc>cbc){

        ans(v,n,obc,cbc+1,s+")");
        }
        
    }
};