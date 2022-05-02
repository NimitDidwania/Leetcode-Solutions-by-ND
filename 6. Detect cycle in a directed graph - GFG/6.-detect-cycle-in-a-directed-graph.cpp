// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s,int V,vector<int>adj[] , vector<bool>&visited , vector<bool>&currStack)
    {
        visited[s]=1;
        currStack[s]=1;
        for(auto child:adj[s]){
            if(visited[child]==false && dfs(child,V,adj,visited,currStack))return 1;
            else if(currStack[child])return true;
        }
        currStack[s]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false) , currRec(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,V,adj,visited,currRec))return 1;
            }
        }
        return false;
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