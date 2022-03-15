#define all(a) a.begin(),a.end()
class Solution {
public:
    void fun(vector<int>&nums,int ind,int prev,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(ind==nums.size()){
            if(curr.size()>1)
            ans.push_back(curr);
            return;
        }   
        if(nums[ind]>=prev)
        {
            curr.push_back(nums[ind]);
            fun(nums,ind+1,nums[ind],curr,ans);
            curr.pop_back();
            
        }
        if(prev!=nums[ind])
            fun(nums,ind+1,prev,curr,ans);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>curr;
        vector<vector<int>>ans,op;
        fun(nums,0,-1000,curr,ans);
        return ans;
    }
    
};