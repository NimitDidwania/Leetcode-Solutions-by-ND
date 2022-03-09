class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            int ans=9;
            int mul=9;
            while(j!=1){ans*=mul--;j--;}
            dp[i]=dp[i-1]+ans;
        }
        return dp[n];
    }
};