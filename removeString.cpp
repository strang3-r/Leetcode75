/*
//Remove character

Given two strings string1 and string2, remove those characters from first string(string1) which are present in second string(string2). Both the strings are different and contain only lowercase characters.
NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).
 

Example 1:

Input:
string1 = "computer"
string2 = "cat"
Output: "ompuer"
Explanation: After removing characters(c, a, t)
from string1 we get "ompuer".
Example 2:

Input:
string1 = "occurrence"
string2 = "car"
Output: "ouene"
Explanation: After removing characters
(c, a, r) from string1 we get "ouene".
 

Your Task:  
You dont need to read input or print anything. Complete the function removeChars() which takes string1 and string2 as input parameter and returns the result string after removing characters from string2  from string1.


Expected Time Complexity:O( |String1| + |String2| )
Expected Auxiliary Space: O(K),Where K = Constant
*/


/*
Approach: 

Keep on iterating string1(outer for loop) and set the flag to 0

In the inner for loop iterate through string2

If any element of string2 matches the corresponding character of string1 then set the flag to 1

After completion of the inner for loop, if the flag is not equal to 1 i.e if the corresponding string1 character is not present in string2 then add that character to the resulting string.

Return the resulting string after the iteration of loops is completed.
*/


//https://practice.geeksforgeeks.org/problems/remove-character3815/1
 
 //{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
          string ans;
  for (int i = 0; i < string1.length(); i++) 
  {
    int flag = 0;
    
    for (int j = 0; j<string2.length(); j++) 
    {
      if (string1[i] == string2[j]) 
      {
        flag = 1;
      }
    }
    if (flag != 1)
      ans.push_back(string1[i]);
  }
  return ans;
}
    
};


//{ Driver Code Starts.
int main() {
    
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    

    return 0;
}

// } Driver Code Ends
