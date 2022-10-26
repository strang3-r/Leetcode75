#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main()
{
    int n,a,ans=0;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(m[a]==0)
        {
            m[a]++;
            ans++;
        }
    }
    cout<<ans;
 
}
