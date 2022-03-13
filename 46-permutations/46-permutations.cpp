class Solution {
public:
    void fun(vector<int>&nums,int ind,vector<int>&curr,vector<vector<int>>&ans)
    {
        int n=nums.size();
        if(ind==n){ans.push_back(curr);}
        for(int i=0;i<n;i++)
        {
            if(nums[i]==-11)continue;
            curr.push_back(nums[i]);
            int restore=nums[i];
            nums[i]=-11;
            fun(nums,ind+1,curr,ans);
            nums[i]=restore;
            curr.pop_back();
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        fun(nums,0,curr,ans);
        return ans;
    }
};