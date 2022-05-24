class Solution {
public:
    int fun(int si,int sj,int di,int dj,vector<vector<int>>&grid){
        int n=grid.size() , m=grid[0].size();
        if(si<0 || sj<0 || si>=grid.size()||sj>=grid[0].size() || grid[si][sj]==-1)return 0;
        if(si==di && sj==dj){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0)return 0;
                }
            }
            return 1;
        }
        int restore = grid[si][sj];
        grid[si][sj]=-1;
        int ans=0;
        ans+= fun(si-1,sj,di,dj,grid);
        ans+= fun(si+1,sj,di,dj,grid);
        ans+= fun(si,sj-1,di,dj,grid);
        ans+= fun(si,sj+1,di,dj,grid);
        grid[si][sj] = restore;
        return ans;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size() , m = grid[0].size() ;
        int si,sj , di,dj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    si=i,sj=j;
                }
                else if(grid[i][j]==2){
                    di=i;dj=j;
                }
            }
        }
        return fun(si,sj,di,dj,grid);
    }
};