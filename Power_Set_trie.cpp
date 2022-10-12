//Problem Statement: Given a string, find all the possible subsequences of the string.

//Examples:

//Example 1:
//Input: str = "abc"
//Output: a ab abc ac b bc c
//Explanation: Printing all the 7 subsequence for the string "abc".

#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}
