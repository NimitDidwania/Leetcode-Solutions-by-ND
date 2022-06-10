class Solution {
public:
    int fun(vector<vector<int>>& piles,int ind,int k,vector<vector<int>>&dp)
    {
        if(k==0 )return 0;                                                    // no more coins can be taken
        if(ind==piles.size())return INT_MIN;                      // no more piles are left
        if(dp[ind][k]!=-1)return dp[ind][k];
        int ans=fun(piles,ind+1,k,dp);                                     // if we take 0 coin from the pile
        int score=0;
        int secAns=INT_MIN;
        for(int i=0;i<k && i<piles[ind].size();i++)                 // taking 1 to k coins from the pile
        {
            score+=piles[ind][i];
            secAns=max(secAns,score+fun(piles,ind+1,k-i-1,dp));
        }
        return dp[ind][k] = max(ans,secAns);                                      
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return fun(piles,0,k,dp);
    }
};
