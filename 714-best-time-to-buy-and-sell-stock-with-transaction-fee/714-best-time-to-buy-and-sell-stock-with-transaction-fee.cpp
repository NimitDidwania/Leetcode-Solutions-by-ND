class Solution {
public:
    int dp[50001][2];
    int fun(int ind,int hold,vector<int>&prices,int fee){
        if(ind==prices.size())return 0;
        if(dp[ind][hold]!=-1)return dp[ind][hold];
        int ans=INT_MIN;
        if(hold==0){
            ans=max(
                max(ans,-fee-prices[ind]+fun(ind+1,hold^1,prices,fee)),
                fun(ind+1,hold,prices,fee)
            );
        }
        else{
                ans=max(
                max(ans,prices[ind]+fun(ind+1,hold^1,prices,fee)),
                fun(ind+1,hold,prices,fee)
            );
        }
        return dp[ind][hold]= ans;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,prices,fee);
    }
};