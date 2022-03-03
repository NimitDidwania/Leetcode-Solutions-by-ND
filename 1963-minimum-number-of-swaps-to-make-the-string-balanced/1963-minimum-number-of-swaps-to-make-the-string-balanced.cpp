class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int close=0;
        int maxClose=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==']'){close++;}
            else close--;
            maxClose=max(maxClose,close);
        }
        return (maxClose+1)>>1;
    }
};