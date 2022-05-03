// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define info pair<int , pair<int,int> >
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>taken(V,false);
        taken[0]=true;
        
        priority_queue<info , vector<info> , greater<info> > pq;
        for(auto x: adj[0]){
            pq.push({x[1] , {0 , x[0]}});
        }
        int mst=0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int from = x.second.first , to = x.second.second , wt= x.first;
            if(taken[to])continue;
            mst+=wt;
            taken[to]=1;
            for(auto x:adj[to]){
                if(!taken[x[0]]){
                    pq.push({x[1],{to,x[0]}});
                }
            }
        }
        return mst;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends