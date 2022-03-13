class Solution {
public:
    bool valid(vector<vector<char>>&board,int i,int j)
    {
        int n=board.size();
        //row
        for(int col=j;col>=0;col--)if(board[i][col]=='Q')return false;
        //col
        for(int row=i;row>=0;row--)if(board[row][j]=='Q')return false;
        //left diagonal
        for(int row=i,col=j;row>=0&&col>=0;row-=1,col-=1)
        {
            if(board[row][col]=='Q')return false;
        }
        //right diagonal
        for(int row=i,col=j;row>=0&&col<n;row-=1,col+=1)
        {
            if(board[row][col]=='Q')return false;
        }
        return true;
    }
    
    void fun(vector<vector<char>>&board,int row,int &ans,int n)
    {
        if(row==n){ans++;return;}
        for(int i=0;i<n;i++){
            if(!valid(board,row,i))continue;
            board[row][i]='Q';
            fun(board,row+1,ans,n);
            board[row][i]='_';
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'_'));
        int ans=0;
        fun(board,0,ans,n);
        return ans;
    }
};