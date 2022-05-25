class Solution {
public:
   
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int j=i-1;
            dp[i]=1;
            for( ;j>=0;j--){
            
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1 ) ;
                    
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);}
        return ans;
    }
};