class Solution {
public:
    int dp[5100][2];
    int fun(int ind,int hold , vector<int>&prices){
        if(ind>=prices.size()){
            return 0;
        }
        int ans=INT_MIN;
        if(dp[ind][hold]!=-1)return dp[ind][hold];
        if(hold==0){
            ans = max( max(ans,
                fun(ind+1,hold,prices) ), 
                -prices[ind]+fun(ind+1,hold^1,prices)
            );
        }
        else{
            ans = max( max(ans,
                fun(ind+1,hold,prices) ), 
                +prices[ind]+fun(ind+2,hold^1,prices)
            );
        }
        return dp[ind][hold]=ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,prices);
    }
};