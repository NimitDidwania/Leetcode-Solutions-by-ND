class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1 , zeroCount=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)zeroCount++;
            else product*=nums[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(zeroCount==0)
            {
                ans.push_back(product/nums[i]);
            }
            else if(zeroCount==1)
            {
                if(nums[i]==0)ans.push_back(product);
                else ans.push_back(0);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};