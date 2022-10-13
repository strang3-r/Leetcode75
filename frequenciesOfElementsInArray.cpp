#include <bits/stdc++.h>
using namespace std;

void printFrequencies (int arr[], int n) {
	int frequency = 1, i = 1;
	while (i < n) {
		while (i < n && arr[i-1] == arr[i]) {
			frequency++;
			i++;
		}
		cout << arr[i-1] <<' ' << frequency << '\n';
		i++;
		frequency = 1;
		if (n == 1 || arr[n-1] != arr[n-2]) {
			cout << arr[n-1] <<' ' << '1' << '\n';
		}
	}
}

int main() {
  int n; cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
  	cin >> arr[i];
  }
  printFrequencies (arr, n);
  return 0;
}
