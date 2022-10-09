/*

Counting Bits


Share
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

*/

vector<int> countBits(int n) {
        vector<int> answer;
        for(int i = 0; i <=n; i++){
            int m = __builtin_popcount(i);
            answer.push_back(m);
        }
        return answer;
    }
