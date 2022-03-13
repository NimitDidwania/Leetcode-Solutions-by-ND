#define all(a) a.begin(),a.end()
class Solution {
public:
    void fun(vector<int>&nums,int ind,vector<int>&curr,vector<vector<int>>&ans)
    {
        int n=nums.size();
        if(ind==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(( i==0 || nums[i]!=nums[i-1]) && nums[i]!=-11)
            {
                curr.push_back(nums[i]);
                int restore=nums[i];
                nums[i]=-11;
                fun(nums,ind+1,curr,ans);
                curr.pop_back();
                nums[i]=restore;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(all(nums));
        vector<vector<int>>ans;
        vector<int>curr;
        fun(nums,0,curr,ans);
        return ans;
    }
};