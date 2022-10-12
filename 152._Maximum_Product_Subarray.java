// Problem link
// https://leetcode.com/problems/maximum-product-subarray/



// Basically to undertand this solution, one should have idea on Kadanes Algorithm which is a DP approach to solve Maximum Subarray Sum.
// This question just replaced sum with product and we know that we got headache with the negative values if you have understood the question properly. 
// So I swapped min and max values at current iteration of negative value.


class Solution {
    public int maxProduct(int[] nums) {
        int max=nums[0], min=nums[0],prod=max;
        for(int i=1;i<nums.length;i++){
            if(nums[i]<0){
                //swap max and min
                int temp=max;
                max=min;
                min=temp;
            }
            max=Math.max(nums[i],nums[i]*max);
            min=Math.min(nums[i],nums[i]*min);
            if(prod<max) prod=max;     
        }
        return prod;
    }
}
