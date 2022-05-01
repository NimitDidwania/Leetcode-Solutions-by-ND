class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(auto x:s){
            if(x=='#' && a.size()==0)continue;
            if(x=='#')a.pop_back();
            else a.push_back(x);
        }
        for(auto x:t){
            if(x=='#' && b.size()==0)continue;
            if(x=='#')b.pop_back();
            else b.push_back(x);
        }
        return a==b;
    }
};