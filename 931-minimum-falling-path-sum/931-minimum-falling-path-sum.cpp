class Solution {
public:
    int fun(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(i>matrix.size()-1)return 0;
        if(j<0||j>=matrix[0].size())return 1e4;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = matrix[i][j]+ min(fun(matrix,i+1,j,dp) ,min(fun(matrix,i+1,j-1,dp) ,
                                                       fun(matrix,i+1,j+1,dp)));
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e4;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        for(int j=0;j<matrix[0].size();j++)
        {
            ans=min(ans,fun(matrix,0,j,dp));
        }
        return ans;
    }
};