#define all(a) a.begin(),a.end()
class Solution {
public:
    
    void fun(vector<int>&candidates,int target,int i,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(target<0)return;
        if(target==0){
                      ans.push_back(curr);
                      return;}
        if(i==candidates.size())return;
        curr.push_back(candidates[i]);
        fun(candidates,target-candidates[i],i+1,curr,ans);
        curr.pop_back();
        int ind=-1,n=candidates.size();
        for(int j=i+1;j<n;j++)if(candidates[j]!=candidates[i]){ind=j;break;}
        if(ind!=-1)
        fun(candidates,target,ind,curr,ans);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>help;
        vector<int>curr;
        sort(all(candidates));
        fun(candidates,target,0,curr,help);
        return help;
    }
};