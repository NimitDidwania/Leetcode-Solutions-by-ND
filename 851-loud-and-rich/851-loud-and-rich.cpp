class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        vector<int>topSort , indegree(n) , ans(n);
        for(int i=0;i<richer.size();i++) {
            int s = richer[i][0] , d = richer[i][1];
            adj[s].push_back(d);
            indegree[d]++;
        }
        // for(auto x:indegree)cout<<x<<" ";
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){q.push(i);
                                ans[i]=i;}
        }
        iota(ans.begin(),ans.end(),0);
        for(auto x:ans)cout<<x<<" ";
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto child : adj[curr]){
                if(quiet[curr]<quiet[child]){
                    quiet[child] = quiet[curr];
                    ans[child] = ans[curr];
                }
                // else {
                //     cout<<child<<endl;
                //     ans[child] = child ;}
            }
            for(auto child : adj[curr]){
                indegree[child]--;
                if(indegree[child]==0)q.push(child);
            }   
        }
        return ans;
    }
};