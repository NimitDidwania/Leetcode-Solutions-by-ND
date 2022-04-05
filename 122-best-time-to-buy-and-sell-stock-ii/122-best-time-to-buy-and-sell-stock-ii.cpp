class Solution {
public:
    int fun(int ind,vector<int>&prices,int hold,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][hold]!=-1)return dp[ind][hold];
        if(hold==0){
            return dp[ind][hold]= max(fun(ind+1,prices,1^hold,dp)-prices[ind] , fun(ind+1,prices,hold,dp));
        }
        else return  dp[ind][hold]= max(fun(ind+1,prices,1^hold,dp)+prices[ind] , fun(ind+1,prices,hold,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return fun(0,prices,0,dp);
    }
};