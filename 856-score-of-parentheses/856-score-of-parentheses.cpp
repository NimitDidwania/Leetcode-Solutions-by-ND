class Solution {
public:
    int fun(string s,int st,int e)
    {
        if(st>e)return 0;
        if(e==st+1)return 1;
        
        int ans=0;
        int open=0;
        int start=st;
        for(int i=st;i<=e;i++ )
        {
            if(s[i]=='(')open++;
            else open--;
            if(open==0)
            {
                int temp=fun(s,start+1,i-1);
                if(temp==0)ans+=1;
                else
                ans+=(2*temp);
                start=i+1;
            }
        }
        return ans;
    }
    
    int scoreOfParentheses(string s) {
        return fun(s,0,s.length()-1);
    }
};