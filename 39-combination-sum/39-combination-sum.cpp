class Solution {
public:
    void fun(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>&candidates,int target){
        if(target == 0){
            ans.push_back(curr);
            return ;
        }
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        if(target>=candidates[ind])
        {
            curr.push_back(candidates[ind]);
            fun(ind,curr,ans,candidates,target-candidates[ind]);
            curr.pop_back();
        }
        fun(ind+1,curr,ans,candidates,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        fun(0,curr,ans,candidates,target);
        return ans;
    }
};