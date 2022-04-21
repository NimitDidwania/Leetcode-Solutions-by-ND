// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++



class Solution
{
	public:
		string is_palindrome(int no)
		{
		    // Code here.
		    
		    string num = to_string(no);
		  //  string temp="";
		    int n=num.size();
		  //  for(int i=n-1;i>=0;i--){
		  //      temp.push_back(num[i]);
		  //  }
		  //  if(temp==num)return "Yes";
		  //  else return "No";
		  int l=0, h=n-1;
		  while(l<h){
		      if(num[l]!=num[h])return "No";
		      l++;
		      h--;
		  }
		  return "Yes";
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends