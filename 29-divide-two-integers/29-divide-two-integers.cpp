class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x =  (long long)dividend/divisor ;
        if(x<INT_MIN)return INT_MIN;
        if(x>INT_MAX)return INT_MAX;
        return x;
    }
};