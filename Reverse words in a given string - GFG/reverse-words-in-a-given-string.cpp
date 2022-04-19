// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverse(string &s,int l,int h){
        while(l<h)swap(s[l++],s[h--]);
    }
    string reverseWords(string s) 
    { 
        // code here 
        // ijdli.like.this.program.very.much
        s+=".";
        for(int start=0;start<s.size(); ){
            int end=start;
            while(s[end]!='.')end++;
            reverse(s,start,end-1);
            start=end+1;
        }
        reverse(s,0,s.size()-1);
        
        return s.substr(1,s.size()-1);
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends