class Solution {
public:
    bool fun(vector<bool>&v,int ind,int x,int n,vector<int>&ans)
    {
        if(ind==x)return 1;
        for(int i=0;i<n;i++)
        {
            int temp = ans[ind-1] ^ (1<<i) ;
            if(v[temp]==0){
                ans.push_back(temp);
                v[temp]=1;
                if(fun(v,ind+1,x,n,ans))return 1;
                ans.pop_back();
                    v[temp]=0;
            }
        }
        return 0;
    }
    
    vector<int> grayCode(int n) {
        vector<int>ans;
        int x= pow(2,n);
        vector<bool>v(x,0);
        v[0]=1;
        ans.push_back(0);
        fun(v,1,x,n,ans);
        return ans;
    }
};