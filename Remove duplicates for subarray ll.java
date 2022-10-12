class Solution {
    public int removeDuplicates(int[] nums) extends Exception {
        if(nums.length==0){
            return 0;
        }
        int x=1,index=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1] && x==1){
                x++;
                nums[index++]=nums[i];
            }
            else if(nums[i]!=nums[i+1]){
                x=1;
                nums[index++]=nums[i];
            }
        }
        nums[index++]=nums[nums.length-1];
        return index;
    }
}
