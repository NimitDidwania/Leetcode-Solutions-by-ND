class Solution {
public:
    int dp[100000][2];
    int fun(int ind ,int turn, vector<int>&val){
        if(ind==val.size())return 0;
        int n=val.size();
        if(dp[ind][turn]!=-1)return dp[ind][turn];
        if(turn==0){
            int score = val[ind]+ fun(ind+1,turn^1,val);
            if(ind<n-1){
                score = max(score,val[ind]+val[ind+1]+fun(ind+2,turn^1,val));
            }
            if(ind<n-2)score = max(score,val[ind]+val[ind+1]+val[ind+2]+fun(ind+3,turn^1,val));
            return dp[ind][turn]= score;
        }
        else{
            int score = fun(ind+1,turn^1,val);
            if(ind<n-1)score=min(score,fun(ind+2,turn^1,val));
            if(ind<n-2)score=min(score,fun(ind+3,turn^1,val));
            return dp[ind][turn]= score;
        }
        
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(auto x:stoneValue)sum+=x;
        int alice =  fun(0,0,stoneValue);
        int bob = sum - alice;
        if(alice>bob)return "Alice";
        else if(alice<bob)return "Bob";
        else return "Tie";
    }
};