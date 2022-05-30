class Solution {
public:
    int n,m;
    int dp[75][75][75];
    int fun(int i,int j,int k,int l,vector<vector<int>>&grid){
        if(i==n)return 0;
        if(k==n)return 0;
        if(i<0 || j<0||i>=n||j>=m)return INT_MIN;
        if(k<0 || l<0||k>=n||l>=m)return INT_MIN;
        int cherries=0;
        if(dp[i][j][l]!=-1)return dp[i][j][l];
        if(i==k && j==l)cherries=grid[i][j];
        else cherries=grid[i][j] + grid[k][l];
        int ans = 0;
        for(int a=-1;a<2;a++){
            for(int s=-1;s<2;s++){
                ans = max(ans,cherries+fun(i+1,j+a,k+1,l+s,grid));
            }
        }
        return dp[i][j][l] = ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
         n=grid.size() , m=grid[0].size();
        return fun(0,0,0,m-1,grid);
    }
};