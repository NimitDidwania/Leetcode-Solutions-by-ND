class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<=10)return {};
        string part = s.substr(0,10);
        vector<string>ans;
        unordered_map<string,int>mp;
        mp[part]++;
        for(int i=1;i<n;i++){
            part =  s.substr(i,10);
            mp[part]++;
        }
        for(auto x:mp){
            if(x.second > 1)ans.push_back(x.first);
        }
        return ans;
        
    }
};