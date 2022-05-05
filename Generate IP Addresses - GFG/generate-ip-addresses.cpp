// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void fun(int ind,string &s,string curr,vector<string>&ans,int dots){
        int n=s.size();
        if(ind==n){
            if(dots==4){
                curr.pop_back();
                ans.push_back(curr);
                curr.push_back('.');
            }
            return;
        }
        if(s[ind]=='0'){
            curr.push_back(s[ind]);
            curr.push_back('.');
            fun(ind+1,s,curr,ans,dots+1);
            curr.pop_back();
            curr.pop_back();
            return;
            
        }
        curr.push_back(s[ind]);
        curr.push_back('.');
        fun(ind+1,s,curr,ans,dots+1);
        curr.pop_back();
        curr.pop_back();
        if(ind<n-1){
            curr.push_back(s[ind]);
            curr.push_back(s[ind+1]);
            curr.push_back('.');
            fun(ind+2,s,curr,ans,dots+1);
            curr.pop_back();
            curr.pop_back();
            curr.pop_back();
        }
        if(ind<n-2){
            string temp = s.substr(ind,3);
            int num = stoi(temp);
            if(num<=255){
                temp.push_back('.');
                fun(ind+3,s,curr+temp,ans,dots+1);
            }
        }
    }
  
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        string curr="";
        int dots=0;
        fun(0,s,curr,ans,dots);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends