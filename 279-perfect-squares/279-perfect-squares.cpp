class Solution {
public:
    int fun(int n,vector<int>&dp){
        if(n<0)return INT_MIN;
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            // if()
            ans = min(ans ,1 + fun(n- i*i,dp));
        }
        return dp[n]= ans;
    }
    
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};