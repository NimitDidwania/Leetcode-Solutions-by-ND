class Solution {
public:
    bool fun(string s,int ind,int open,vector<vector<int>>&dp){
        if(ind==s.size()){
            if(open==0)return 1;
            else return 0;
        }
        if(dp[ind][open]!=-1)return dp[ind][open];
        if(s[ind]=='('){
            return dp[ind][open] = fun(s,ind+1,open+1,dp);
        }
        else if(s[ind]==')') return dp[ind][open]= open!=0&&fun(s,ind+1,open-1,dp);
        else {
            return dp[ind][open] = (fun(s,ind+1,open,dp)
                                    ||fun(s,ind+1,open+1,dp)
                                   || open!=0&&fun(s,ind+1,open-1,dp));
        }
    }
    
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(s,0,0,dp);
    }
};