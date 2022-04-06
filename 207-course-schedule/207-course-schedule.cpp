class Solution {
public:
    bool dfs(int s,vector<int>adj[],vector<int>&vis)
    {
        vis[s]=1;
        for(auto x:adj[s]){
            if(vis[x]==0){
                if(dfs(x,adj,vis))return 1;
                }
            else{
                if(vis[x]==1)return 1;
            }
        }
        vis[s]=2;
        return 0;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis))return false;
            }
        }
        return true;
    }
};