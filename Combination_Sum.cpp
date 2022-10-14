class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        sort(candidates.begin(),candidates.end());
        combination(candidates, target, sum, 0, ans);
        return ans;
    }
    
    void combination(vector<int> & nums, int target, vector<int> &sum, int idx, vector<vector<int>>& ans)
     {
         if(target==0)
        {
            return ans.push_back(sum);
        }
        
        if(target<0)
        {
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) 
                continue; 
            
                 sum.push_back(nums[i]);
                 combination(nums,target-nums[i],sum,i+1,ans);
                 sum.pop_back();
        }
     }
};
