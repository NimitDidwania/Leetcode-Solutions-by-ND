class Solution {
public:
    void fun(vector<bool>&v,int ind,int from,int k,int n,vector<int>&curr,vector<vector<int>>&ans){
        if(ind==k){ 
            if(n==0)
            ans.push_back(curr);
            return;
        }
        for(int i=from;i<=9;i++)
        {
            if(v[i]==0 && n>=i)
            {
                curr.push_back(i);
                v[i]=1;
                fun(v,ind+1,i+1,k,n-i,curr,ans);
                curr.pop_back();
                v[i]=0;
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
     
        vector<bool>v(10,0);
        vector<int>curr;
        vector<vector<int>>ans;
        fun(v,0,1,k,n,curr,ans);
        return ans;
    }
};