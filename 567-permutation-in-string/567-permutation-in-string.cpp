class Solution {
public:
    bool checkInclusion(string p, string s) {
        
     if(s.length()<p.length())return 0;
        int sLen=s.length(),pLen=p.length();
         vector<int> ct(26,0);
        for(int j=0;j<p.length();j++){
            ct[p[j]-'a']++;
            ct[s[j]-'a']--;
        }
        for(int i=0;i<=sLen - pLen ; i++)
        {
            bool flag=0;
            if(i!=0)
            {
                ct[s[i-1]-'a']++;
                ct[s[i+pLen-1]-'a']--;
            }
            for(int i=0;i<26;i++)if(ct[i]!=0)flag=1;
            if(!flag)return 1;
        }
        return 0;
    }
};