#define all(a) a.begin(),a.end()
class Solution {
public:
    void fun(vector<int>&nums,int ind,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(ind==nums.size()){ans.push_back(curr);return;}
        curr.push_back(nums[ind]);
        fun(nums,ind+1,curr,ans);
        curr.pop_back();
        int j=ind;
        while(j<nums.size()&&nums[j]==nums[ind])j++;
        fun(nums,j,curr,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(all(nums));
        vector<int>curr;
        vector<vector<int>>ans;
        fun(nums,0,curr,ans);
        return ans;
    }
};