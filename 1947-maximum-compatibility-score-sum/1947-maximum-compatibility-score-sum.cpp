class Solution {
public:
    int fun(int ind,vector<vector<int>>&students , vector<vector<int>>&mentors,vector<int>&v){
        
        int m=students.size();
        int n=students[0].size();
        if(ind==m){
            return 0;
        }
        int ct=0 ,ans=INT_MIN;
        for(int i=0;i<m;i++){
            if(v[i]==-1){
                v[i]=1;
            for(int j=0;j<n;j++){
                if(students[ind][j] == mentors[i][j])ct++;
            }
                ans = max(ans,ct+fun(ind+1,students,mentors,v));
                v[i]=-1;
                ct=0;
            }
        }
        return ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        vector<int>v(n,-1);
        return fun(0,students,mentors,v);
    }
};