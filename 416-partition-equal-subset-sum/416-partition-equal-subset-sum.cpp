class Solution {
public:
    bool fun(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)return 1;
        if(ind==nums.size())return 0;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        if(nums[ind]<=sum)
        {
            return dp[ind][sum]=fun(nums,ind+1,sum-nums[ind],dp) || fun(nums,ind+1,sum,dp);
        }
        else return dp[ind][sum]=fun(nums,ind+1,sum,dp);
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums)sum+=x;
        if(sum&1)return 0;
        else{
            vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
            return fun(nums,0,sum/2,dp);
        }
    }
};