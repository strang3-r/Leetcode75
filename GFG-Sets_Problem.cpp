//Given two arrays A and B contains integers of size N and M, the task is to find numbers
// which are present in the first array, but not present in the second array.
// Example 1:

// Input: N = 6, M = 5
// A[] = {1, 2, 3, 4, 5, 10}
// B[] = {2, 3, 1, 0, 5}
// Output: 4 10
// Explanation: 4 and 10 are present in
// first array, but not in second array.

// Constraints:
// 1 ≤ N, M ≤ 10^6
// -10^6 ≤ A[i], B[i] ≤ 10^6

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    cin>>arr1[i];
    for(int i=0;i<m;i++)
    cin>>arr2[i];
    unordered_set <int> s;
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (int i = 0; i < n; i++)
        if (s.find(arr1[i]) == s.end())
            cout << arr1[i] << " ";
// Agr element set me nahi hota hai to set ka end point return krdeta hai
// Aur agr element hota hai to wo s.end ke equal nahi hoga wo us element ka pointer dedega
// s.find(element) returns an iterator pointing to the element, if the iterator reaches s.end() 
// that means if it reaches the end of set s, which actually means that the element is not in the set 
// and we had reached the end searching the whole set, then cout<<a[i]<<" "
}