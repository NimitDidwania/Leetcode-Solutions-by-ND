class Solution {
public:
    string countAndSay(int n) {
           if(n==1)return "1";
           string prev = countAndSay(n-1);
           string ans="";
           for(int i=0;i<prev.size();){
               int j=i;
               while(j<prev.size() && prev[j]==prev[i])j++;
               int ct=j-i;
               
               ans+=to_string(ct);
               ans.push_back(prev[i]);
               i=j;
           }
        return ans;
    }
};