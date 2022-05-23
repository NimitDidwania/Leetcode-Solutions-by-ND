class Solution {
public:
   
    int x;
    int fun(int ind,vector<int>&buckets, vector<int>&nums,map<vector<int>,int>&m){
        
        if(ind >= nums.size())return 0;
        if(m.find(buckets)!=m.end())return m[buckets];
        int ans = INT_MIN;
        for(int i=0;i<x;i++){
            if(buckets[i]<2){
            buckets[i]++;
            int curr =( nums[ind]&(i+1)) + fun( ind+1,buckets,nums,m);
            buckets[i]--;
             ans = max ( ans, curr);
            }
        }
        return m[buckets] =  ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n=nums.size();
        map<vector<int>,int>m;
        vector<int>buckets(10,0);
        x=numSlots;
        return fun(0,buckets,nums,m);
    }
};