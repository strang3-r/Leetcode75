class Solution {
public:
    bool isPalindrome(string s) {
        //checking and making the string 
      for(int i =0;i<s.length();i++){
          if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'|| s[i]>'z')&&(s[i]<'0' || s[i]>'9')){
              s.erase(i,1);
              i--;
          }
      }
        if(s.compare("")==0){
            return true;
        }
        //all small
        for(int i =0;i<s.length();i++){
                s[i]=tolower(s[i]);
        }
        //palindrome check
        int i =0;
        int j = s.length()-1;
        while(s[i]){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
};