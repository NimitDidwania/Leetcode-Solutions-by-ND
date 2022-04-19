// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int n, int sum);
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];  //array of size n
            
        for(int i = 0; i < n; i++)
            cin>>arr[i]; //Input the array
             
        int sum; 
        cin>>sum;
          
        cout<< sumExists(arr, n, sum) <<endl;    
            
	}
}// } Driver Code Ends


//User function Template for C++

int sumExists(int arr[], int n, int sum){
    
    
    //code here
    sort(arr,arr+n);
    int l=0 , h=n-1;
    while(l<h){
        int s=arr[l]+arr[h];
        if(s==sum)return 1;
        else if(s>sum)h--;
        else l++;
    }
    return 0;
}