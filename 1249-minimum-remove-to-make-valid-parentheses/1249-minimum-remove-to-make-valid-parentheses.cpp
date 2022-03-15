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
                else rem.insert(i);
            }
        }
        while(!st.empty()){rem.insert(st.top());st.pop();}
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&& s[i]<='z')ans.push_back(s[i]);
            else
            if(rem.find(i)==rem.end())ans.push_back(s[i]);
        }
        return ans;
    }
};