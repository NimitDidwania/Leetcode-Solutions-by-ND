// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
   int startingOccurence(int arr[],int n,int x){
    int low = 0 , high=n-1 ; 
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            //corner case
            if(mid==0){
                return mid;
            }
            if(arr[mid-1]==x)high=mid-1;
            else {
                 return mid;
            }
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
   }
   int lastOccurence(int arr[],int n,int x){
       int low=0,high=n-1;
       while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            //corner case
            if(mid==n-1){
                return mid;
            }
            if(arr[mid+1]==x)low=mid+1;
            else {
                 return mid;
            }
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
   }
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>ans(2);
    // ans[0]->first occurence
    // ans[1]->last occurence
    ans[0]=startingOccurence(arr,n,x);
    ans[1]=lastOccurence(arr,n,x);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends