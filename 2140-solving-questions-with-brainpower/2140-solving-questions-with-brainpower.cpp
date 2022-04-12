class Solution {
public:
    long long fun(int ind,vector<vector<int>>& ques,vector<long long>&dp)
    {
        if(ind>=ques.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=max( (long long)ques[ind][0] + fun(ind+ques[ind][1]+1 , ques,dp), 
                   fun(ind+1 , ques,dp));
    }
    long long mostPoints(vector<vector<int>>& ques) {
        vector<long long>dp(ques.size(),-1);
        return fun(0,ques,dp);
    }
};