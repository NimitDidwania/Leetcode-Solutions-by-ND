class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0,a=0,b=0;
        int n=costs.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<costs.size();i++)
            pq.push({abs(costs[i][0]-costs[i][1]),i});
        for(int i=0;i<costs.size();i++)
        {
            auto x=pq.top();pq.pop();
            int ind=x.second;
            if((costs[ind][0] > costs[ind][1]))
            {
                if(2*b  <n){
                ans+=costs[ind][1];
                    b++;
                }
                else {
                    ans+=costs[ind][0];
                    a++;
                }
            }
            else{
                if(2*a  <n){
                ans+=costs[ind][0];
                    a++;
                }
                else {
                    ans+=costs[ind][1];
                    b++;
                }
            }
            
        }
        return ans;
    }
};