class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++)mx=max(mx,nums[i]);
        vector<int>count(mx+1,0);
        
        for(int i=0;i<n;i++)count[nums[i]]++;
        vector<int>dp(mx+1,0);
        dp[1]=count[1];
        if(mx>=2)dp[2]=max(dp[1],2*count[2]);
        for(int i=3;i<=mx;i++)
        {
            dp[i]=max(dp[i-1],i*count[i] + dp[i-2]);
        }
        return dp[mx];
    }
};