class Solution {
public:
    
    bool isValid(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || i>=grid.size()||j<0||j>=grid[0].size())return 0;
        if(grid[i][j]!='1')return 0;
        return 1;
    }
    
    void island(vector<vector<char>>&grid,int i,int j)
    {
        grid[i][j]='2';
        if(isValid(grid,i+1,j))
        island(grid,i+1,j);
        if(isValid(grid,i-1,j))
        island(grid,i-1,j);
        if(isValid(grid,i,j+1))
        island(grid,i,j+1);
        if(isValid(grid,i,j-1))
        island(grid,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='1')continue;
                if(grid[i][j]=='1')
                {
                    ans++;
                    island(grid,i,j);
                }
            }
        }
        return ans;
    }
};