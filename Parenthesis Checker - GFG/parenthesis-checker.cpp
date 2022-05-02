// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        for(char ch : x)
        {
            if(ch == '{' || ch=='(' || ch=='[')s.push(ch);
            else{
                if( ch==')'){
                    if(!s.empty() &&s.top()=='('){
                        s.pop();
                    }
                    else return 0;
                }
                else if( ch==']'){
                    if(!s.empty() &&s.top()=='[')s.pop();
                    else return 0;
                }
                else if( ch=='}'){
                    if(!s.empty() &&s.top()=='{')s.pop();
                    else return 0;
                }
            }
        }
        return s.size()==0 ; 
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends