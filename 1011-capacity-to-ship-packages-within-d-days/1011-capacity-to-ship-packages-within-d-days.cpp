class Solution {
public:
    bool isValid(vector<int>&weights,int days , int capacity)
    {
        int sum=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>capacity)return false;
            if(sum+weights[i]>capacity){d+=1;sum=weights[i];}
            else {
                sum+=weights[i];
            }
        }
        return (d<=days);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=INT_MIN , high = 0;
        for(int i=0;i<weights.size();i++)
        {
            low=max(low,weights[i]);
            high+=weights[i];
        }
        int cap=INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isValid(weights,days,mid)){cap=mid;high=mid-1;}
            else low=mid+1;
        }
        return cap;
    }
};