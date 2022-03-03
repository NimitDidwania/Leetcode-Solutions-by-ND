class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        for(int i=0;i<n;i++)
        {
            int low=i,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int sum = nums[mid];
                if(i!=0)sum-=nums[i-1];
                if(sum>=target)ans=min(ans,mid-i+1),high=mid-1;
                else low=mid+1;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};