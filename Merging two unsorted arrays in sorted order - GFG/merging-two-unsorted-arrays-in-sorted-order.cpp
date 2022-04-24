// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Your code goes hereclass Solution{
	
class Solution{
	public:
	void sortedMerge(int a[], int b[], int arr[],int n, int m)
	{
	   // Your code goes here
	   sort(a,a+n);
	   sort(b,b+m);
	   int ind=0;
	   int i=0,j=0;
	   while(i<n && j<m){
	       if(a[i]>b[j]){arr[ind++]=b[j];j++;}
	       else arr[ind++]=a[i++];
	   }
	   while(i<n){
	       arr[ind++]=a[i++];
	   }
	   while(j<m)arr[ind++]=b[j++];
	}
};
	  


// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> b[i];
	    }
	    
	    int res[n+m];

      
        Solution ob;
        ob.sortedMerge(a,b,res,n,m);

        for(int i = 0;i<n+m;i++){
	        cout << res[i] << " ";
	    }
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends