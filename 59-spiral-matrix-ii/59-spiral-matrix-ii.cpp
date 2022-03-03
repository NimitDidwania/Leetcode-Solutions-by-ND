class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int left=0,right=n-1, top=0,bottom=n-1;int d=1;
        while(left<=right && top<=bottom){
        if(left>right)break;
        for(int i=left;i<=right;i++)
        {
            ans[top][i]=d++;
        }
        top++;
           if(top>bottom)break; 
        for(int j=top;j<=bottom;j++)
            ans[j][right]=d++;
        right--;
            if(left>right)break;
        for(int i=right;i>=left;i--)
            ans[bottom][i]=d++;
        bottom--;
            if(top>bottom)break;
        for(int j=bottom;j>=top;j--)
            ans[j][left]=d++;
        left++;
        }
        return ans;
    }
};