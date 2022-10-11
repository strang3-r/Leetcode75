class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        int mask = 0;
        
        for(auto i : nums){
            ans = ans ^ i;
            ans = ans ^ mask;
            mask++;
        }
        
        return ans;
    }
};
