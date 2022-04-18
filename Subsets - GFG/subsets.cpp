// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void fun(int ind, vector<int>&A,vector<int>&curr,vector<vector<int>>&ans){
        
        if(ind==A.size()){
            ans.push_back(curr);
            return;
        }
        //two choices
        //first choice "include"
        curr.push_back(A[ind]);
        fun(ind+1,A,curr,ans);
        curr.pop_back();
        fun(ind+1,A,curr,ans);
    }
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int> >ans;
        vector<int>curr;
        fun(0,A,curr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends