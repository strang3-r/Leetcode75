// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        int count{0};
        string s{to_string(x)};
        for(int i{0}; i<s.size()/2; ++i){
            if(s.at(i) == s.at(s.size()-i-1)){
                count++;
            }
        }
        if(count == s.size()/2){
            return true;
        }
        else{
            return false;
        }
    }
};
