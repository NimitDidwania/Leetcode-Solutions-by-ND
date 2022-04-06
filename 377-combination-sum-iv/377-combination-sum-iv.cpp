class Solution {
public:
    int fun(vector<int>&nums,int target,vector<int>&dp){
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int total=0;
        for(auto x:nums){
            total+=fun(nums,target-x,dp);
        }
        return  dp[target]=total;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return fun(nums,target,dp);
    }
};