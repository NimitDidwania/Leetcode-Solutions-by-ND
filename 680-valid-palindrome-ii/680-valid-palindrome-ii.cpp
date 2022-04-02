class Solution {
public:
    
    bool fun(string s,int l ,int h){
        while(l<h){
            if(s[l]!=s[h])return 0;
            l++;h--;
        }
        return 1;
    }
    
    bool validPalindrome(string s) {
        int l=0 , h=s.length()-1;
        while(l<h){
            if(s[l]!=s[h]){
                break;
            }
            l++;h--;
        }
        return fun(s,l+1,h) || fun(s,l,h-1);
    }
};