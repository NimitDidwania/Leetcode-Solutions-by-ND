class Solution {
    int n;
public:
    int fun(int ind,int time,vector<int>&satisfaction,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][time]!=-1)return dp[ind][time];
        return dp[ind][time]=max( time*satisfaction[ind] + fun(ind+1,time+1,satisfaction,dp),
                  fun(ind+1,time,satisfaction,dp));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(0,1,satisfaction,dp);
    }
};