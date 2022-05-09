class Solution {
public:
    void fun(int ind,string &digits,string &curr,vector<string>&ans,unordered_map<int,string>&mp){
        if(ind == digits.size()){
            if(curr.size()!=0)
            ans.push_back(curr);
            return;
        }
        int d = digits[ind] -'0' ;
        for(auto x: mp[d]){
            curr.push_back(x);
            fun(ind+1,digits,curr,ans,mp);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string curr;
        
        unordered_map<int,string>m;
        m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";
        m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
        fun(0,digits,curr,ans,m);
        return ans;
    }
};