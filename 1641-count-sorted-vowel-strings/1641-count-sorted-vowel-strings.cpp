class Solution {
public:
    map<char,string>mp;
    
    void fun(string &curr,string &s,int &ct,int n){
        if(curr.size()==n){ct++;return;}
        char prev = curr[curr.size()-1];
        string x = mp[prev];
        for(int i=0;i<x.size();i++){
            curr.push_back(x[i]);
            fun(curr,s,ct,n);
            curr.pop_back();
        }
        
    }
    
    int countVowelStrings(int n) {
        mp['a']="aeiou";
        mp['e']="eiou";
        mp['i']="iou";
        mp['o']="ou";
        mp['u']="u";
        string s="aeiou";
        string curr;
        int res=0;
        for(int i=0;i<5;i++){
            curr.push_back(s[i]);
            int ct=0;
            fun(curr, s,ct,n);
            curr.pop_back();
            res+=ct;
        }
        return res;
    }
};