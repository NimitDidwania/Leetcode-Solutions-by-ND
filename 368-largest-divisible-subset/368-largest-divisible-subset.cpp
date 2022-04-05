class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int x=0;
            for(int j=i-1;j>=0;j--){
                
                if(nums[i]%nums[j]==0){
                    x=max(x,dp[j]);
                    // if(i==n-1)cout<<x<<endl;
                }
            }
                dp[i]+=x;
            
        }
        int ind=0;
        for(int i=0;i<n;i++){
            if(dp[i]>dp[ind])ind=i;
        }
        int prev=ind;
        vector<int>ans;ans.push_back(nums[prev]);
        for(int i=ind;i>=0;i--){
            if(dp[prev]==dp[i]+1   &&   nums[prev]%nums[i]==0){ans.push_back(nums[i]);prev=i;}
        }
        for(int i=0;i<n;i++)cout<<dp[i]<<" ";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};