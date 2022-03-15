#define ff first 
#define ss second
class Solution {
public:
    bool check(vector<vector<char>>&board,int x,int y)
    {
        //row
        unordered_set<char>s;
        for(int j=0;j<9;j++)
        {
            if(board[x][j]=='.')continue;
            if(s.find(board[x][j])!=s.end())return false;
            s.insert(board[x][j]);
        }
        s.clear();
        //column
        for(int i=0;i<9;i++)
        {
            if(board[i][y]=='.')continue;
            if(s.find(board[i][y])!=s.end())return false;
            s.insert(board[i][y]);
        }
        //grid
        int a=3*(x/3) , b=3*(y/3);
        
        s.clear();
        for(int i=a;i<a+3;i++)
        {
            for(int j=b;j<b+3;j++)
            {
                if(board[i][j]=='.')continue;
                if(s.find(board[i][j])!=s.end())return false;
            s.insert(board[i][j]);
            }
        }
        return true;
    }
    
    
    bool fun(vector<vector<char>>&board,int ind,int v[][2],int n)
    {
        if(ind==n){
          return 1;
        }
        for(int i=1;i<=9;i++)
        {
            char restore=board[v[ind][0]][v[ind][1]];
            board[v[ind][0]][v[ind][1]]= '0'+i;
            
            if(check(board,v[ind][0],v[ind][1]))
            {
                if(fun(board,ind+1,v,n))return 1;
            }
            board[v[ind][0]][v[ind][1]]=restore;
        }
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int ct=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='.')ct++;
        }int x=0;
        int v[ct][2];
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='.'){v[x][0]=i;v[x][1]=j;x++;}
        }
        fun(board,0,v,ct);
    }
};