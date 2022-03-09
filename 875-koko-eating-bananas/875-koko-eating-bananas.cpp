class Solution {
public:
    bool check(vector<int>&piles,int k,int h)
    {
        int hrs=0;
        for(int i=0;i<piles.size();i++)
        {
            hrs+=ceil((double)piles[i]/k);
        }
        return hrs<=h ;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(int i=0;i<piles.size();i++)high=max(high,piles[i]);
        int ans;
        while(low<=high)
        {
            int k= low+(high-low)/2;
            if(check(piles,k,h))ans=k,high=k-1;
            else low=k+1;
        }
        return ans;
    }
};