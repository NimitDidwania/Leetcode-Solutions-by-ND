// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int s,int V,vector<int> adj[],vector<bool>&visited){
        visited[s]=1;
        for(auto child:adj[s]){
            if(!visited[child])dfs(child,V,adj,visited);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    for(int i=0;i<V;i++){
	        vector<bool>visited(V,false);
	        dfs(i,V,adj,visited);
	        int ct=0;
	        for(int i=0;i<V;i++)if(visited[i]==0)ct++;
	        if(ct==0)
	        return i;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends