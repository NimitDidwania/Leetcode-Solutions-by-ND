class Solution {
public:
    bool dfs(int s,int color,vector<vector<int>>&graph,vector<int>&visited,vector<int>&col){
        visited[s]=1;
        col[s]=color;
        for(auto child:graph[s]){
            if(!visited[child]){
                if(dfs(child,color^1,graph,visited,col)==0)return 0;
            }
            else {
                if(col[s]==col[child])return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0) ; vector<int>col(n,-1);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
               if( !dfs(i,0,graph,visited,col))return false;
            }
        }
        return true;
    }
};