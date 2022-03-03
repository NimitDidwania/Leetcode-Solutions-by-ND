class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return 1;
            else{
                if(nums[low]==nums[high] && nums[high]!=target){low++;high--;}
                else if( nums[low]<=nums[mid])
                {
                    if(target>=nums[low]&&target<nums[mid])high=mid--;
                    else low=mid+1;
                }
                else{
                    if(target>nums[mid] && target<=nums[high])low=mid+1;
                    else high=mid-1;
                }
            }
        }
        return 0;
    }
};