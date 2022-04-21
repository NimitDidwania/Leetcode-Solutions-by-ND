// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
        // // if(a==b)return 1;
        // // else return 0;
        // return a==b;
        int count[26]={0};
        for(int i=0;i<a.size();i++){
            count[a[i] - 'a']++;
        }
        
        for(int i=0;i<b.size();i++){
            count[b[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0)return false;
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends