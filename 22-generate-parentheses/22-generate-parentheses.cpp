class Solution {
public:
    void fun(string curr , vector<string>&ans,int open , int close,int n){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n)
        fun(curr+"(",ans,open+1,close,n);
        if(open > close)
        fun(curr+")",ans,open,close+1,n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open =0 ,close =0;
        string curr;
        fun(curr,ans,open,close,n);
        return ans;
    }
};