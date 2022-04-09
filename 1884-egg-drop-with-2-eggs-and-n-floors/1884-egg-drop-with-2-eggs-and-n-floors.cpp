class Solution {
public:
    int fun(int n,int eggs,vector<vector<int>>&dp){
        if(n==1)return 1;
        if(eggs==1)return n;
        if(dp[n][eggs]!=-1)return dp[n][eggs];
        int ans=10000;
        for(int i=1;i<=n;i++){
           ans=min(ans,1+ max(fun(n-i,eggs,dp) , fun(i-1,eggs-1,dp)) ) ;
        }
        return dp[n][eggs]=ans;
    }
    
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return fun(n,2,dp);
    }
};