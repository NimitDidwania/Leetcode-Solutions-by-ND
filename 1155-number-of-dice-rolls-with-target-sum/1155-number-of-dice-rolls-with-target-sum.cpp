class Solution {
public:
    long long dp[31][10001];
    long long m = 1000000007;
    long long fun(int dice , int n,int k,long long target){
        
        if(dice==n+1){
            if(target==0)return 1;
            return 0;
        }
        if(dp[dice][target]!=-1)return dp[dice][target];
        long long total=0;
        for(long long i=1;i<=k&&i<=target;i++){
            total= (total+fun(dice+1,n,k,target-i))%m;
        }
        return dp[dice][target] = total;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return (int) fun(1,n,k,(long long)target);
    }
};