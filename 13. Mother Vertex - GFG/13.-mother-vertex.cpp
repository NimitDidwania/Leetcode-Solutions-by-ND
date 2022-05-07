// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int s,int V,vector<int> adj[],bool visited[],stack<int>&st){
        visited[s]=1;
        for(auto child:adj[s]){
            if(!visited[child])dfs(child,V,adj,visited,st);
        }
        st.push(s);
    }
    void dfs2(int s,int V,vector<int> adj[],bool visited[],int &count){
        visited[s]=1;
        count++;
        for(auto child:adj[s]){
            if(!visited[child])dfs2(child,V,adj,visited,count);
        }
        
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int entry=0;
	    bool visited[V]={false};stack<int>st;
	    for(int i=0;i<V;i++){
	       // if(entry==1)return -1;
	        if(!visited[i])
	        dfs(i,V,adj,visited,st);
	       // entry++;
	    }
	    for(int i=0;i<V;i++)visited[i]=false;
	    int count=0;
	    dfs2(st.top(),V,adj,visited,count);
	    if(count==V)
	    return st.top();
	    else return -1;
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