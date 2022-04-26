class Solution {
public:
    int characterReplacement(string str, int k) {
        int n=str.size() ,ans=0;
        vector<int>count(26,0);
        int s=0 ;
        for(int i=0;i<n;i++){
            count[str[i]-'A']++;
            int mx=0,useless=0;
            for(int j=0;j<26;j++){
                if(count[j]>count[mx])mx=j;
                useless+=count[j];
            }
             useless-=count[mx];
            while(s<n && useless > k){
                cout<<"in";
                count[str[s]-'A']--;
                int mx=0 , less=0;
                for(int i=0;i<26;i++){
                    if(count[i]>count[mx])mx=i;
                    less+=count[i];
                }
                s++;
                less-=count[mx];
                useless=less;
            }
            ans=max(ans,i-s+1);
        }
        return ans;
    }
};