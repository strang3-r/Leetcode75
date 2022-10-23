class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int fo=search(nums,target,true);
        v.push_back(fo);
        if(fo==-1){
            v.push_back(-1);
            return v;
        }
        int lo=search(nums,target,false);
        v.push_back(lo);
        return v;
    }
    int search(vector<int>& nums, int target,bool choice){
        int ans=-1;
        int start=0,end=nums.size()-1;
       
        while(start<=end){
             int mid=start + (end - start) / 2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                ans=mid;
                if(choice){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }

};