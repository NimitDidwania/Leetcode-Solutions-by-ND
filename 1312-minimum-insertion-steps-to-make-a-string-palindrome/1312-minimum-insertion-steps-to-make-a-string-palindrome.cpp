class Solution {
public:
    int dp[501][501];
    int fun(int low,int high,string &s){
        if(low>high)return 0;
        if(dp[low][high]!=-1)return dp[low][high];
        if(s[low]==s[high]){
            return dp[low][high] = fun(low+1,high-1,s);
        }
        else {
            return dp[low][high] = 1 + min(fun(low,high-1,s) , fun(low+1,high,s));
        }
        
    }
    
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s.size()-1,s);
    }
};