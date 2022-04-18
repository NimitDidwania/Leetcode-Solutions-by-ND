// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void fun(int i,int N){
        if(i==N+1){
            return;
        }
        cout<<i<<" ";
        fun(i+1,N);
    }
    void printNos(int N)
    {
        //Your code here
        fun(1,N);
    }
};

// { Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends