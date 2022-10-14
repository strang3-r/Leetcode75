class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int indx;
         if(nums[0]>target){
                indx = 0;
            }
        else if(nums[nums.size()-1]<target){
                indx = nums.size();
            }
        else{
        for(int i =0;i< nums.size();i++){
            if(nums[i]==target){
                indx=i;
            }
            else if(nums[i]<target && nums[i+1]>target){
                indx =  i+1;
            }
        }
        }
        return indx;
    }
};