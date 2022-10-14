class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> A = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto x : words) {
            string str = "";
            for(auto ch : x) str += A[ch - 'a'];
            st.insert(str);
        }
        return st.size();
    }
};