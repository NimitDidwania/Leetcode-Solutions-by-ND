class Solution {
public:
    int fun(int ind,int ct,vector<int>&values,vector<vector<int>>&dp){
        if(ct==2)return 0;
        
        if(ind==values.size())return INT_MIN;
        if(dp[ind][ct]!=-1)return dp[ind][ct];
        if(ct==0){
            return  dp[ind][ct]= max(values[ind]+ind+fun(ind+1,ct+1,values,dp)  ,
                        fun(ind+1,ct,values,dp));
        }
        else if(ct==1){
            return  dp[ind][ct]=max(values[ind]-ind+fun(ind+1,ct+1,values,dp),
                      fun(ind+1,ct,values,dp));
        }
        else{
            return 0;
        }
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(3,-1));
        return fun(0,0,values,dp);
    }
};