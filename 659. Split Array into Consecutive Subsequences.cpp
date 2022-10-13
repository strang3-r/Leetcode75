class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int, int> mp;
        for(auto x: a) mp[x]++;
        for(auto x: a) {
            if(mp[x] == 0) continue;
            int freq = mp[x], count = 0, currElement = x;
            while(mp.count(currElement) && mp[currElement] >= freq) {
                freq = max( freq, mp[currElement]);
                mp[currElement]--;
                currElement++;
                count++;
            }
            if(count < 3) return 0;
        }
        return 1;
    }
};