#include <bits/stdc++.h>
using namespace std;

int maxSum (int arr[], int n) {
  int maxEnding = arr[0], result = arr[0];
  for (int i = 1; i < n; i++) {
    maxEnding = max (maxEnding + arr[i], arr[i]);
    result = max (maxEnding, result);
  }
  return result;
}
             
int main() {
  int n; cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int result = maxSum (arr, n);
  cout << result << '\n';
  return 0;
}
