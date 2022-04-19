// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void fun(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>arr,int sum){
        
        if(ind==arr.size()){
            if(sum==0){
                ans.push_back(curr);
            }
            return;
        }
        
        if(arr[ind]<=sum){
            curr.push_back(arr[ind]);
            fun(ind,curr,ans,arr,sum-arr[ind]);
            curr.pop_back();
        }
        int i=ind+1;
        while(i<arr.size()&&arr[i]==arr[ind])i++;
        fun(i,curr,ans,arr,sum);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        vector<int>curr;
        fun(0,curr,ans,A,B);
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends