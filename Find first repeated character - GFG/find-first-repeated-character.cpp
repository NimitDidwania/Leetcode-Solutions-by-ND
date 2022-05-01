// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    string ans;
    unordered_set<char>st;
    for(auto ch:s){
        if(st.find(ch)!=st.end()){ans.push_back(ch); return ans ;}
        st.insert(ch);
    }
    ans.push_back('-');
    ans.push_back('1');
    return ans;
}