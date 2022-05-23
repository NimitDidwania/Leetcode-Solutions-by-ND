class Solution {
public:
    int dp[601][101][101];
    int fun(int ind,vector<string>&strs,int m,int n){
        if(m<0 || n<0)return INT_MIN;
        if(ind==strs.size())return 0;
        if(dp[ind][m][n]!=-1)return dp[ind][m][n];
        int z=0 , o=0;
        for(auto x:strs[ind]){
            if(x=='0')z++;
            else o++;
        }
        int choice1 = 1 + fun(ind+1,strs,m-z,n-o);
        int choice2 = fun(ind+1,strs,m,n);
        return dp[ind][m][n] = max(choice1,choice2);
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(0,strs,m,n);
    }
};