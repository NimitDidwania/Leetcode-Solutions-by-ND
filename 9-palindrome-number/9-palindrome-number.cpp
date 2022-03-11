class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        string a=to_string(x);
        int l=0,h=a.length()-1;
        while(l<h){
            if(a[l]!=a[h])return 0;
            l++;h--;
        }
        return 1;
    }
};