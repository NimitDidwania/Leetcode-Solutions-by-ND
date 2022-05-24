class Solution {
public:
    
    
     int longestValidParentheses(string s) {
         stack<int>st;
         int ans=0;
         st.push(-1);
         int n=s.size();
         for(int i=0;i<n;i++){
             if(s[i]=='(')st.push(i);
             else{
                 st.pop();
                 if(st.empty())st.push(i);
                 ans = max (ans ,i - st.top());
             }
         }
         return ans;
    }
};