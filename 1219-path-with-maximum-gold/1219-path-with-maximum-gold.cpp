class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)return 0;
        int temp=grid[i][j];
        grid[i][j]=0;
        int ans = temp +max( max(dfs(grid,i+1,j) , dfs(grid,i-1,j)) ,                                          max(dfs(grid,i,j+1),dfs(grid,i,j-1)));
        grid[i][j]=temp;
        return ans;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0)
                {
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};