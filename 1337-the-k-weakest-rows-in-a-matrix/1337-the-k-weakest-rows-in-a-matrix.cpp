class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        int r=mat.size() , c = mat[0].size();
        for(int i=0;i<r;i++)
        {
            int j=0;
            while(j<c&&mat[i][j]==1)j++;
            if(pq.size()==k){
                if(pq.top().first>j){
                    pq.pop();
                    pq.push({j,i});
                }
            }
            else pq.push({j,i});
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};