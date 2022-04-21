// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int ct[26]={0};
        for(int i=0;i<str.size();i++)ct[str[i]-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            if(ct[i]>ct[ans])ans=i;
        }
        return ans + 'a';
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends