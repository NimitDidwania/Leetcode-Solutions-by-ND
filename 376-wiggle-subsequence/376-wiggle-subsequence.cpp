class Solution {
public:
    //0 means greater
    int dp[1001][1001][2];
    int fun(int ind,int prev,int choice,vector<int>&nums){
        if(ind==nums.size())return 0;
        if(dp[ind][prev][choice]!=-1)return dp[ind][prev][choice] ;
        int a=0,b=0;
        if(choice==0){
             a=0;
            if(nums[ind]>prev){
                a=1+fun(ind+1,nums[ind],choice^1,nums);
            }
            a=max(a,fun(ind+1,prev,choice,nums));
        }
        else{
            if(nums[ind]<prev){
                b=1+fun(ind+1,nums[ind],choice^1,nums);
            }
            b=max(b,fun(ind+1,prev,choice,nums));
        }
        return dp[ind][prev][choice] = max(a,b);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,max(fun(i+1,nums[i],0,nums) ,fun(i+1,nums[i],1,nums) ));
        }
        return 1+ ans;
    }
};