class Solution {
public:
    int fun(int ind,int n,vector<unordered_set<int>>&v,unordered_set<int>&used){
        if(ind==1){return 1;}
        int ct=0;
        for(auto x:v[ind]){
            if(used.find(x)==used.end()){
               used.insert(x);
               ct+=fun(ind-1,n,v,used);
               used.erase(x); 
            }
        }
        return ct;
    }
    
    int countArrangement(int n) {
        
        vector<unordered_set<int>>v(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i%j==0 || j%i==0)v[i].insert(j);
            }
        }
        unordered_set<int>used;
        return fun(n,n,v,used);
    }
};