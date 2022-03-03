class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int left=0,right=matrix[0].size()-1, top=0,bottom=matrix.size()-1;
        while(left<=right && top<=bottom){
        if(left>right)break;
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
           if(top>bottom)break; 
        for(int j=top;j<=bottom;j++)
            ans.push_back(matrix[j][right]);
        right--;
            if(left>right)break;
        for(int i=right;i>=left;i--)
            ans.push_back(matrix[bottom][i]);
        bottom--;
            if(top>bottom)break;
        for(int j=bottom;j>=top;j--)
            ans.push_back(matrix[j][left]);
        left++;
        }
        return ans;
    }
};