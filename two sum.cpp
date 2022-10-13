// Link for problem
https://leetcode.com/problems/two-sum/ 

// Map based approach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int> m;
         for(int i=0; i<nums.size(); i++){
             if(m.find(target-nums[i])==m.end()) m[nums[i]]=i;
             else return {i,m[target-nums[i]]};
         }
        return{};
    }
};

// Two pointer based approach
// Time Complexity - O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;++i){
            arr[i].first=nums[i];
            arr[i].second=i;
        }
        
        // Sort all the elements
        sort(arr.begin(),arr.end());
        
        int i=0,j=n-1;
        while(i<j){
            // If sum of elements at i and j equals target then we have found the answer
            if(arr[i].first+arr[j].first==target){
                ans.push_back(arr[i].second);
                ans.push_back(arr[j].second);
                break;
            }
            // If sum of elements at i and j is greater than the target then we have to reduce the jth element
            else if(arr[i].first+arr[j].first>target)
                --j;
            // If sum of elements at i and j is smaller than the target then we have to increase the ith element
            else
                ++i;
        }
        
        return ans;
    }
};