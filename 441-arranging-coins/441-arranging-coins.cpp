class Solution {
public:
    int arrangeCoins(int n) {
        
        int low=0,high=n, ans=n;
        while(low<=high)
        {
            long long mid=(long long)low+(high-(long long)low)/2;
            long long coinsReq = mid*(mid+1)/2;
            if(coinsReq<=n)ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};