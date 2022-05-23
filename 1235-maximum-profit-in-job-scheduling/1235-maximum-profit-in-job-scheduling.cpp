class Solution {
public:
    int dp[100000];
    int fun(int ind,vector<pair<pair<int,int>,int>>&data){
        
        if(ind >= data.size())return 0;
        int ans = INT_MIN;
        if(dp[ind]!=-1)return dp[ind];
        
            int j=ind+1;
            while(j<data.size()&&data[j].first.first < data[ind].first.second )j++;
            ans = max(ans, data[ind].second + fun(j,data));
        
        ans = max(ans , fun(ind+1,data));
        return dp[ind] =  ans;
        
    }
    
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>data;
        int n=start.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)data.push_back({{start[i],end[i]},profit[i]});
        sort(data.begin(),data.end());
        
        return fun(0,data);
    }
};