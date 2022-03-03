class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if((mid==0 || nums[mid]!=nums[mid-1]) && ( mid==n-1||nums[mid]!=nums[mid+1]))
            {
                return nums[mid];
            }
            else
            {
                if(mid!=n-1&&nums[mid]==nums[mid+1])mid++;
                
                if((mid&1))low=mid+1;
                else high=mid-2;
            }
        }
        return -1;
    }
};