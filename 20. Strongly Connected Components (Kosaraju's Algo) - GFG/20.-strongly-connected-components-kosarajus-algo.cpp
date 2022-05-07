// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void fun(int s,int v,vector<int>adj[],stack<int>&st,bool visited[]){
	    visited[s]=1;
	    for(auto child:adj[s]){
	        if(!visited[child])fun(child,v,adj,st,visited);
	    }
	    st.push(s);
	}
	void dfs(int s,vector<vector<int>>&adj,bool visited[]){
	    visited[s]=1;
	    for(auto child:adj[s]){
	        if(!visited[child])dfs(child,adj,visited);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int>s;
        bool visited[V] ={ false };
        int ans=0;
        for(int i=0;i<V;i++){
        if(!visited[i])
        fun(i,V,adj,s,visited);
        }
        vector<vector<int>>transpose(V);
        for(int i=0;i<V;i++){
            for(auto child:adj[i]){
                transpose[child].push_back(i);
            }
        }
        for(int i=0;i<V;i++)visited[i]=false;
        while(!s.empty()){
            int curr=s.top();
            if(!visited[curr]){
                dfs(curr,transpose,visited);
                ans++;
            }
            s.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends