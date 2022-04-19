// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void fun(string s,string curr, vector<string>&ans){
	        if(curr.size()==s.size()){
	            ans.push_back(curr);
	            return ;
	        }
	        for(int i=0;i<s.size();i++){
	            if(s[i]!=' '){
	                char restore=s[i];
	                s[i]=' ';
	                fun(s,curr+restore,ans);
	                s[i]=restore;
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>ans;
		    string curr="";
		    fun(s,curr,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends