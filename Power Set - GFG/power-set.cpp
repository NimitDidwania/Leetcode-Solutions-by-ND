// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	   void fun(int ind,string s,string &curr,vector<string>&ans){
	        //base case
	        if(ind==s.size()){
	            if(curr.size()!=0)
	            ans.push_back(curr);
	            return;
	        }
	        
	        curr.push_back(s[ind]);
	        fun(ind+1,s,curr,ans);
	        curr.pop_back();
	        fun(ind+1,s,curr,ans);
	   }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string curr="";
		    fun(0,s,curr,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
        
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends