int m=1000000007;
class Solution {
public:
    long long dp[100002][3][5];
    long long fun(int day,int absents,int consLate,int n){
        if(day == n+1)return 1;
        if(dp[day][absents][consLate] !=-1)return dp[day][absents][consLate]%m ;
        long long ans = 0;
        ans = (ans + fun(day+1,absents,0,n))%m;
        if(absents ==0 )
            ans = (ans +  fun(day+1,absents+1,0,n))%m;
        if(consLate<2)
            ans = (ans + fun(day+1,absents,consLate+1,n))%m;
        return dp[day][absents][consLate] = ans;
    }
    
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return (int) fun(1,0,0,n);
    }
};