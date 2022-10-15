class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0,x1=0,x2=0,pos=-1;
        for(int i=0;i<nums.size();i++)
            x=x^nums[i];
        for(int i=0;i<=31;i++)
        {
            if(x&(1<<i))
            {
                pos=i;
                break;
            }
    
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&(1<<pos))
                x1=x1^nums[i];
            else 
                x2=x2^nums[i];
        }
        vector<int> vect;
        vect.push_back(x1);
        vect.push_back(x2);
        return vect;
    }
};