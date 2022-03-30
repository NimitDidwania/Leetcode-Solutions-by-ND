class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i = 0 , j = c-1;
        while( i<r &&  0<=j)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
            i+=1;
             
            else
             j-=1;
        }       
        return false;
    }
};