// this question is third in leetcode weekly contest #314

class Solution {
public:
    
    char getMinChar(vector<int> &freq)
    {
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]!=0)return i+'a'; 
        }
        
        return 'A';
    }
    
    string robotWithString(string s) {
        // while we dont get smallest in string add in stack
        
        int len = s.size();
        vector<int> freq(26);
        for(auto ch:s)
        {
            freq[ch-'a']++;
        }
        
        stack<char> st;
        string ans = "";
        
        for(auto ch:s)
        {
            st.push(ch);
            freq[ch-'a']--;
            //bhai terse chota koi nahi h ans me add hoja -> st ka top , min in freq se bhi minimum hai
            while(!st.empty() && st.top()<=getMinChar(freq))
            {
                ans.push_back(st.top());
                st.pop();
            }
            
        }
        
       
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        
        return ans;
    }
};
