class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = string(n,'a');
        int len = n; 
         for(int i=0;i<n-1;i++)
         {
             for(int ch=0;ch<26;ch++)
             {
                 if((len-1)*26 >= (k-(ch+1)))
                 {
                     ans[i]='a'+ch;
                     k-=(ch+1);
                     len--;
                     break;
                     
                 }
             }
         }
        ans[n-1]='a'+k-1;
        return ans;
    }
};