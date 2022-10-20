#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        
        int n=nums.size();
        
        unordered_set<int>st;
//         for(int i=0;i<n;i++){
//             st.insert(nums[i]);
// }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int x=nums[i];
int val=target-x;
            if(st.find(val)!=st.end()){

            ans.push_back(i);
                for(int j=0;j<n;j++){

                if(nums[j]==val){
                    ans.push_back(j);
                  break;
}
                }
            }
            st.insert(nums[i]);
        }
            
        return ans;
    }
};