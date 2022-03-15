class Solution {
public:
    
    void fun(string &s,int ind,string curr,vector<string>&ans)
    {
        if(ind==s.length()){
            ans.push_back(curr);
            return;
        }
        if(s[ind]>='a'&&s[ind]<='z'){
            curr.push_back(s[ind]-'a'+'A');
            fun(s,ind+1,curr,ans);
            curr.pop_back();
        }
        else if(s[ind]>='A'&& s[ind]<='Z')
        {
            curr.push_back(s[ind]-'A'+'a');
            fun(s,ind+1,curr,ans);
            curr.pop_back();
        }
        curr.push_back(s[ind]);
        fun(s,ind+1,curr,ans);
        curr.pop_back();
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string curr="";
        fun(s,0,curr,ans);
        return ans;
    }
};