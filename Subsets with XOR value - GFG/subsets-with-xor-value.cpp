// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    void fun(int ind,vector<int>&arr,int n,int k,int x,int &ct){
        if(ind==n){
            if(k==x)ct++;
            return;
        }
        fun(ind+1,arr,n,k,x^arr[ind],ct);
        fun(ind+1,arr,n,k,x,ct);
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        int x = 0;
        int ct=0;
        fun(0,arr,N,K,x,ct);
        return ct;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends