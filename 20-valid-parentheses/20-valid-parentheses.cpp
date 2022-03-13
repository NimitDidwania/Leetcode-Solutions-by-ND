class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='{'||s[i]=='('||s[i]=='[')st.push(s[i]);
            else{
                if(s[i]=='}'){
                    if(st.size()==0)return 0;
                    if(st.top()=='{')
                    st.pop();
                    else return 0;
                }
                else if(s[i]==')'){
                    if(st.size()==0)return 0;
                   if( st.top()=='(')
                    st.pop();
                    else return 0;
                }
                else{
                    if(st.size()==0)return 0;
                    if(st.top()=='[')
                        st.pop();
                    else return 0;
                }
                
            }
        }
        return (st.size()==0)?1:0;
    }
};