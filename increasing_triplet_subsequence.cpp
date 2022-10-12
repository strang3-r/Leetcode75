#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l=nums.size();
        if(l<3) return false;
        int min1=INT_MAX,min2=INT_MAX;
        
        for(int i=0;i<l;i++){
            if(nums[i]<=min1){
               min1=nums[i];
            }
            else if(min1<=nums[i] && nums[i]<=min2){
               min2=nums[i];
            }
            else{
                   return true;
               }
               
            
        }
        return false;
    }
};