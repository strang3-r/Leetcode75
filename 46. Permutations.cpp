/*
leetcode problem no 46 Permutations

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& pers, vector<int>& per, vector<int>& nums){
        if(per.size() == nums.size()){
            pers.push_back(per);
        }else{
            for(int e : nums){
                if(find(per.begin(), per.end(), e) != per.end()){
                    continue;
                }
                per.push_back(e);
                backtrack(pers, per, nums);
                per.pop_back();
            }
        }
    };
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> pers;
        vector<int> per;
        
        backtrack(pers, per, nums);
        
        return pers;
    }
};
