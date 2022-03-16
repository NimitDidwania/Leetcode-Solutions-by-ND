class Solution {
public:
    void kadane(vector<int>&nums,int ind , int curr,int &ans)
    {
        if(ind==nums.size())return;
        
        if(curr+nums[ind]>=nums[ind]){
            ans=max(ans,curr+nums[ind]);
            kadane(nums,ind+1,curr+nums[ind],ans);
        }
        else 
        {
            ans=max(ans,nums[ind]);
            kadane(nums,ind+1,nums[ind],ans);
        }
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int a1=nums[0];
        kadane(nums,1,nums[0],a1);
        int sum=0;
        bool ok=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]>=0)ok=1;
            nums[i]*=(-1);
        }
        int a2=nums[0];
        if(ok)
        kadane(nums,1,nums[0],a2);
        else return a1;
        return max(a1 , sum+a2);
    }
};