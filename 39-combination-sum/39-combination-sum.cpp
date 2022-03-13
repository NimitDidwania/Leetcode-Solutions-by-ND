class Solution {
public:
    void fun(vector<int>&candidates,int target,int i,vector<int>&curr,vector<vector<int>>&ans){
        //base case
        if(target<0)return;
        if(target==0){ans.push_back(curr);return;}
        if(i==candidates.size())return;
        curr.push_back(candidates[i]);
        fun(candidates,target-candidates[i],i,curr,ans);
        curr.pop_back();
        fun(candidates,target,i+1,curr,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        fun(candidates,target,0,curr,ans);
        return ans;
    }
};