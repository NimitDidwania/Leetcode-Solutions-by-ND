class Solution {
public:
    void fun(vector<vector<int>>&graph,int ind,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(ind==graph.size()-1){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<graph[ind].size();i++)
        {
            curr.push_back(graph[ind][i]);
            fun(graph,graph[ind][i],curr,ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>curr;
        vector<vector<int>>ans;
        curr.push_back(0);
        fun(graph,0,curr,ans);
        return ans;
    }
};