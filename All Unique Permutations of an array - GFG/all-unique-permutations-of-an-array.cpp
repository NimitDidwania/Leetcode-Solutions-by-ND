// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void fun(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>&arr , int n){
        if(ind==n){
            ans.push_back(curr);
            return;
        }
        int prev=-1;
        for(int i=0;i<n;i++){
            if(arr[i]!=0 && arr[i]!=prev){
                curr.push_back(arr[i]);
                int restore = arr[i];
                arr[i]=0;
                fun(ind+1,curr,ans,arr,n);
                arr[i]=restore;
                curr.pop_back();
            }
            prev=arr[i];
        }
        
    }
    
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        vector<int>curr;
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        fun(0,curr,ans,arr,n);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends