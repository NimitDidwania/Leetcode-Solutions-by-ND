// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //dfs solution 
    // bool dfs(int s,int v ,vector<bool>&visited ,  vector<int>adj[],int parent){
       
    //     visited[s]=1;
    //     for(auto child:adj[s]){
    //         if(child!=parent){
    //             if(visited[child])return true;
    //             else if( dfs(child,v,visited,adj,s))return true;
    //         }
    //     }
    //     return false;
    // }
    
    // bool isCycle(int V, vector<int> adj[]) {
    //     // Code here
    //     vector<bool>visited(V,false);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             if(dfs(i,V,visited,adj,-1))return true;
    //         }
    //     }
    //     return false;
    // }  
    bool bfs(int s,int V,vector<bool>&visited , vector<int>adj[]){
        queue<int>q;
        vector<int>parent(V,-1);
        int grandParent =-1;
        q.push(s);
        
        while(!q.empty()){
            auto curr=q.front();
            visited[curr]=true;
            q.pop();
            for(auto child:adj[curr]){
                if(child!=parent[curr]){
                    if(visited[child])return true;
                    else q.push(child);
                }
                parent[child]=curr;
            }
        }
        return false;
    }
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,V,visited,adj))return true;
            }
        }
        return false;
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends