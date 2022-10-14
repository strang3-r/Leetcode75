class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int prev=INT_MIN, cnt=0, ans=0;
        for(auto x: nums) {
            if(x > prev) {
                cnt++;
                ans = max(ans, cnt);
                prev=x;
            }
            else {
                cnt=1;
                ans=max(ans, cnt);
                prev=x;
            }
        }
        return ans;
    }
};