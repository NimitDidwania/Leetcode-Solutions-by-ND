class Solution {
public:
    int fun(int ind,int type,int transactions,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(transactions == 4 )return 0;
        if(ind == prices.size()){
            if(transactions <= 4)return 0;
            return INT_MIN;}
        if(dp[ind][type][transactions]!=-1)return dp[ind][type][transactions];
        
        if(type==0){
            return dp[ind][type][transactions]= max(-prices[ind]+fun(ind+1,type+1,transactions+1,prices,dp),
                     fun(ind+1,type,transactions,prices,dp) );
        }
        else{
            return dp[ind][type][transactions] = max(prices[ind]+fun(ind+1,type-1,transactions+1,prices,dp),
                    fun(ind+1,type,transactions,prices,dp)  );
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(5,vector<int>(5,-1)));
        return fun(0,0,0,prices,dp);
    }
};