class Solution {
public:
    int dp[366];
    int  fun(int ind , vector<int>&days,vector<int>&costs){
        if(ind == days.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int plan1 = costs[0] + fun(ind+1,days,costs);
        int till = days[ind]+6;
        int i=ind+1;
        while(i<days.size() && days[i]<=till)i++;
        int plan2 = costs[1] + fun(i,days,costs);
        till = days[ind]+29 , i=ind+1;
        while(i<days.size() && days[i]<=till)i++;
        int plan3 = costs[2] + fun(i,days,costs);
        return dp[ind] = min(plan1 , 
                                   min(plan2,plan3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return fun(0,days,costs);
    }
};