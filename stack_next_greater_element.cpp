// https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
// problem


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int nge[n];
    for(int i=0;i<n;i++){
        nge[i]=-1;
    }
    stack<int>st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty())
            nge[i] = st.top();
        }
        st.push(nums[i]);
      }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" "<<nge[i]<<endl;
    }
