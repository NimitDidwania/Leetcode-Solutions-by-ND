class Solution {
public:
    bool dfs(vector<vector<char>>&board,int i,int j,int ind,string word)
    {
        //base case
        if(ind==word.size())return true;
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[ind])
            return false;
        char temp=board[i][j];
        board[i][j]=' ';
        if(dfs(board,i+1,j,ind+1,word)
         ||dfs(board,i-1,j,ind+1,word)
         ||dfs(board,i,j+1,ind+1,word)  
         ||dfs(board,i,j-1,ind+1,word))  
            return 1;
        board[i][j]=temp;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0]&&dfs(board,i,j,0,word))
                    return 1;    
            }
        }
        return false;
    }
};