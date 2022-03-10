class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){dp[i][i]=1;if(s[i+1]==s[i])dp[i][i+1]=2;}
        int gap=2;
        for(int gap=2;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(dp[i+1][j-1]&&s[i]==s[j])dp[i][j]=1;
            }
        }
        int ct=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){if(dp[i][j])ct++;}
        }
        return ct;
    }
};