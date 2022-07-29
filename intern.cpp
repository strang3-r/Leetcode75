#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



vector<string> split(string s) {
  string ans = "";
  vector<string> v;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 32) {
      v.push_back(ans);
      ans = "";
    } else {
      ans += s[i];
    }
  }
  v.push_back(ans);
  return v;
}

string process(string s) {
  string ans = "";
  for(int i = 0; i < s.size(); i++) {
    if(s[i] >= 'a' && s[i] <= 'z' or s[i] >= 'A' && s[i] <= 'Z' or s[i] >= '0' && s[i] <= '9' ) {
      ans += s[i];
    }
  }
  return ans;
}

string StringChallenge(string sen) {

  vector<string> v = split(sen);
  
  for(int i = 0; i < v.size(); i++) {
    v[i] = process(v[i]);
  }
  sort(v.begin(), v.end(), [&](string a, string b) {
    return a.size() > b.size();
  });

  return v[0];

}



int main(void) { 
   
  string temp = "hello wrold &hdjlnv";
  cout << StringChallenge(temp);
  return 0;
    
}