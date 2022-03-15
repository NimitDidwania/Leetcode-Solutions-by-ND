class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int>st;
        unordered_set<int>rem;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&& s[i]<='z')continue;
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty())st.pop();
                else s[i]='A';
            }
        }
        while(!st.empty()){s[st.top()]='A';st.pop();}
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&& s[i]<='z')ans.push_back(s[i]);
            else
            if(s[i]!='A')ans.push_back(s[i]);
        }
        return ans;
    }
};