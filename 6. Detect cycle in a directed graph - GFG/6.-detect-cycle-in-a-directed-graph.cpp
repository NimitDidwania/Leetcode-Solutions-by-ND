// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s,int V,vector<int>adj[] , vector<int>&visited )
    {
        visited[s]=1;
        for(auto child:adj[s]){
            if(visited[child]==0 && dfs(child,V,adj,visited))return 1;
            else if(visited[child]==1)return true;
        }
        visited[s]=2;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto child:adj[curr]){
                indegree[child]--;
                if(indegree[child]==0)q.push(child);
            }
            count++;
        }
        return count<V ;
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