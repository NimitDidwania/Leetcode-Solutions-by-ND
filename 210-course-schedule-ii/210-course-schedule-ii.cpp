class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        int r = pre.size();
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto child:adj[i]){
                indegree[child]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        int ct=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ct++;
            ans.push_back(curr);
            for(auto child : adj[curr]){
                indegree[child]--;
                if(indegree[child]==0)q.push(child);
            }
        }
        vector<int>temp;
        return (ct!=n)? temp: ans;
    }
};