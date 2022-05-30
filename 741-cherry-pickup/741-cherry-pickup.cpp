class Solution {
public:
    int n;
    int dp[51][51][51][51];
    int forward(int i,int j,int k,int l, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n||j>=n||grid[i][j]==-1)return -1000;
        if(k<0 || l<0 || k>=n||l>=n||grid[k][l]==-1)return -1000;
        if(i==n-1 && j==n-1){
            return  grid[i][j];
        }
        if(k==n-1 && l == n-1)return grid[i][j];
        if(dp[i][j][k][l]!=-1)return dp[i][j][k][l];
        int cherries = 0;
        if(i==k && j==l)cherries=grid[i][j];
        else cherries= grid[i][j] + grid[k][l] ;
        return dp[i][j][k][l]= cherries + max(max(forward(i,j+1,k,l+1,grid) , forward(i+1,j,k,l+1,grid)),
                              max(forward(i,j+1,k+1,l,grid),forward(i+1,j,k+1,l,grid))
                              );
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = 0; n = grid.size();
        ans += forward(0,0,0,0,grid);
        return ans<=0? 0 : ans;
    }
};