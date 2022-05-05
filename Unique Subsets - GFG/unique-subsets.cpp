// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void fun(int ind,vector<int>&arr,vector<int>&curr,vector<vector<int>>&ans){
        if(ind==arr.size()){
            ans.push_back(curr);
            return;
        }
        int n=arr.size();
        curr.push_back(arr[ind]);
        fun(ind+1,arr,curr,ans);
        curr.pop_back();
        int j=ind;
        while(j<n && arr[j]==arr[ind])j++;
        fun(j,arr,curr,ans);
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(),arr.end());
        vector<int>curr;
        vector<vector<int>>ans;
        fun(0,arr,curr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends