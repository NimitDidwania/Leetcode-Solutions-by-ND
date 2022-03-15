class Solution {
public:
    
    bool isValid(vector<vector<int>>&m,int i ,int j,int x,int y)
    {
        if(i<0||i>=m.size()||j<0||j>=m[0].size()||m[i][j]<=m[x][y])return false;
        return true;
    }
    
    int fun(vector<vector<int>>&m,int i,int j,vector<vector<int>>&dp)
    {
        //base case
        if(!isValid(m,i-1,j,i,j)&&
           !isValid(m,i+1,j,i,j)&&
           !isValid(m,i,j-1,i,j)&&
           !isValid(m,i,j+1,i,j))
            return 1;
            int u=0,d=0,l=0,r=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isValid(m,i-1,j,i,j))
             u=fun(m,i-1,j,dp);
        if(isValid(m,i+1,j,i,j))
             d=fun(m,i+1,j,dp);
        if(isValid(m,i,j-1,i,j))
             l=fun(m,i,j-1,dp);
        if(isValid(m,i,j+1,i,j))
             r=fun(m,i,j+1,dp);
        return dp[i][j]= 1 + max(max(u,d),max(l,r));        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans=max(ans,fun(matrix,i,j,dp));
            }
        }
        return ans;
    }
};