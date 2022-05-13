class Solution {
public:
    int dp[100000][3];
    int fun(int ind,int remainder,vector<int>&nums){
        if(ind == nums.size()){
            if(remainder==0)return 0;
            return INT_MIN;
        }
        if(dp[ind][remainder]!=-1)return dp[ind][remainder] ;
        int ans = INT_MIN;
        ans=max(ans,nums[ind]+fun(ind+1,(remainder+nums[ind])%3 , nums));
        ans=max(ans,fun(ind+1,remainder,nums));
        return dp[ind][remainder]=ans;
    }
    
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,nums);
    }
};