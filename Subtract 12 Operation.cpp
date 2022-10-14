#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long


	int n,a[20000],s;
	void solve(){
	    cin>> n;s=0;
	    for(int i=1;i<=n;++i) cin >> a[i];
	    for(int i=n;i>1;--i)
	    if(a[i]>0){
	        a[i-1]-=a[i]/2;
	        a[i]=a[i]%2;
	        if(a[i]==1&&(a[i-1]%2==1||((i==2)&&a[1]>0))){
	            a[i]=-1;
	            a[i-1]--;
	        }
	    }
	    for(int i=1;i<=n;++i) s+=abs(a[i]);
	    cout << s << endl;
	}
	
	signed main(){
	    int T;
	    cin >> T;
	    while(T--) solve();
	}
	
