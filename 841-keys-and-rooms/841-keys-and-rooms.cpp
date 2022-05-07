class Solution {
public:
    void dfs(int s,vector<vector<int>>&rooms,vector<bool>&visited,int &ct){
        visited[s]=1;
        ct++;
        for(auto child:rooms[s]){
            if(!visited[child])dfs(child,rooms,visited,ct);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(),ct=0;
        vector<bool>visited(n,false);
        dfs(0,rooms,visited,ct);
        return ct== n;
    }
};