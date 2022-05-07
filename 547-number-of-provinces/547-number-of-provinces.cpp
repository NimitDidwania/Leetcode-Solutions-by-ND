class Solution {
public:
    void dfs(int s,vector<bool>&visited,vector<vector<int>>&adj)
    {
        visited[s]=1;
        for(int i=0;i<adj[s].size();i++){
            if(adj[s][i] && !visited[i]){
                dfs(i , visited,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size() , ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                ans++;
            }
        }
        return ans;
    }
};