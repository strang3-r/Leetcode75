// Problem: https://leetcode.com/contest/weekly-contest-311/problems/sum-of-prefix-scores-of-strings/
// Author: vrintle
// Category: LeetCode Hard

/*

Problem statement
-----------------

You are given an array words of size n consisting of non-empty strings.

We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

*/

struct Trie {
    map<char, Trie*> mp;
    int cnt;
    Trie() {
        cnt = 0;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        int n = words.size();
        for(int i = 0; i < n; i++) {
            Trie *t = root;
            for(auto& e: words[i]) {
                if(t->mp.find(e) == t->mp.end()) {
                    t->mp[e] = new Trie();
                }
                t = t->mp[e];
            }
            t->cnt++;
        }
        function<int(Trie*)> dfs = [&](Trie *t) {
            for(auto& e: t->mp) {
                t->cnt += dfs(e.second);
            }
            return t->cnt;
        };
        dfs(root);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            Trie *t = root;
            for(auto& e: words[i]) {
                t = t->mp[e];
                ans[i] += t->cnt;             
            }
        }
        return ans;
    }
};
