#include<bits/stdc++.h>
using namespace std;

void activity_selection(vector<int> u, vector<int> v, int n)
{
    sort(v.begin(),v.end());
}

int main()
{
    vector<int> start,end;
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        start.push_back(u);
        end.push_back(v);
    }

    activity_selection(u,v,n);
    return 0;
}