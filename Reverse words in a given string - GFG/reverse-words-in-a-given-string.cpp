// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        s+=".";
        for(int i=0;i<s.length();){
            int j=i;
            while(s[j]!='.')j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        reverse(s.begin(),s.end());
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