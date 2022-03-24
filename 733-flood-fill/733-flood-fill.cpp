class Solution {
public:
    void dfs(vector<vector<int>>&img,int r,int c,int colAt,int color)
    {
        if(r<0||r>=img.size()||c<0||c>=img[0].size()||img[r][c]!=colAt)
            return;
        img[r][c]=-1;
        dfs(img,r+1,c,colAt,color);
        dfs(img,r-1,c,colAt,color);
        dfs(img,r,c-1,colAt,color);
        dfs(img,r,c+1,colAt,color);
        img[r][c]=color;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int colAt=image[sr][sc];
        dfs(image,sr,sc,colAt,newColor);
        return image;
    }
};