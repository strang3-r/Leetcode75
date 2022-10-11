#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	// your code goes here
	ll p;
	cin>>p;
	while(p--){
	    ll m,a=0,b=0;
	    cin>>m;
	    vector<ll> x(m,0),y(m,0);
	    for(ll i=0;i<m;i++)cin>>x[i];
	    for(ll i=0;i<m;i++){
	        cin>>y[i];
	        a+=(x[i]-y[i]);
	        b= b+abs(x[i]-y[i]);
	    }
	    
	    if(a!=0)cout<<-1<<endl;
	    else if(b%2!=0)cout<<-1<<endl;
	    else cout<<b/2<<endl;
	}
	return 0;
}
