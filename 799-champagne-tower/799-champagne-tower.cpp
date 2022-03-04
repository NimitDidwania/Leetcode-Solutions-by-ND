class Solution {
public:
    
    
    
    double champagneTower(int poured, int query_row, int query_glass) {
        int row=query_row+1 , col= 2*query_row +1;
         vector<vector<double>> dp(row,vector<double>(col,-1.0));
         int gap=col/2 ;
        for(int i=0;i<row;i++)
        {
            int glasses=i+1;
            for(int j=gap;j<col && glasses!=0;j+=2){dp[i][j]=0.0;glasses--;}
            gap--;
        }
        
        dp[0][col/2]=(double)poured;
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++){
                if(dp[i][j]==-1.0)continue;
               
            if(j!=0&& dp[i-1][j-1]>1)
            {
               
                    double excess = dp[i-1][j-1]-1.0;
               
                    dp[i-1][j-1]-=excess;
                
                    dp[i][j]+=excess;
               
                
            }
            if(j!=col-1 && dp[i-1][j+1]>1)
            {
                double excess = dp[i-1][j+1]-1.0;
                    dp[i-1][j+1]-=excess/2;
                    dp[i][j]+=excess/2;
            }
        }
        }
        
        int ct=-1;
        double ans;
        for(int i=0;i<col;i++)
        {
            if(dp[row-1][i]!=-1.0){
                ct++;
                if(ct==query_glass){ans= dp[row-1][i];break;}
            }
        }
        return (ans>1.0)?1.0:ans;
    }
};