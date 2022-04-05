// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s,int parent,vector<int>&vis,vector<int>adj[]){
        vis[s]=1;
        for(auto child:adj[s]){
            if(vis[child]==0){
                if(dfs(child,s,vis,adj))return 1;
            }
            else if(vis[child]==1){
                return 1;
            }
        }
        vis[s]=2;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
       vector<int> visited(V,0);
       for(int i=0;i<V;i++){
           if(visited[i]==0){
               if(dfs(i,-1,visited,adj))return 1;
           }
       }
       return 0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends