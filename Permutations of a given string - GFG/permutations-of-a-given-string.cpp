// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	   void fun(int ind,string &s,string &curr ,vector<string>&ans)
        {
            if(ind==s.size()){
                ans.push_back(curr);
                return;
            }
            
            for(int i=0;i<s.size();i++){
                if(s[i]!=' '){
                    char restore = s[i];
                    curr.push_back(s[i]);
                    s[i]=' ';
                    fun(ind+1,s,curr,ans);
                    curr.pop_back();
                    s[i]=restore;
                }
            }
        }	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    vector<string>ans;
		    string curr="";
		    fun(0,S,curr,ans);
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