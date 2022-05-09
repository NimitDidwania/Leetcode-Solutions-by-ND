class Solution {
public:
    void fun(int ind,string &s,string &curr,vector<string>&ans,int dots){
        int n=s.size();
        if(ind==n){
            if(dots==4){
                curr.pop_back();
                ans.push_back(curr);
                curr.push_back('.');
            }
            return;
        }
        curr.push_back(s[ind]);
        curr.push_back('.');
        fun(ind+1,s,curr,ans,dots+1);
        curr.pop_back();
        curr.pop_back();
        if(s[ind]!='0'){
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
                string temp;
                temp.push_back(s[ind]);temp.push_back(s[ind+1]);temp.push_back(s[ind+2]);
                if(stoi(temp)<=255){
                    curr+=temp;
                    curr.push_back('.');
                    fun(ind+3,s,curr,ans,dots+1);
                    curr.pop_back();curr.pop_back();curr.pop_back();curr.pop_back();
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string curr;
        fun(0,s,curr,ans,0);
        return ans;
    }
};