class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> last(26,-1);
        for(int i=0;i<n;i++)last[s[i]-'a']=i;
        vector<int>ans;
        for(int i=0;i<n; )
        {
            int currLast=last[s[i]-'a'];
            int j=i;
            while(j<=currLast)
            {
                if(last[s[j]-'a']>currLast)currLast=last[s[j]-'a'];
                j++;
            }
            ans.push_back(currLast-i+1);
            i=currLast+1;
        }
        return ans;
    }
};