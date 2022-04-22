class Solution {
public:
    bool check(vector<int>&nums,int mid,int maxOperations){
        int op=0;
        for(int i=0;i<nums.size();i++){
            op+=ceil(nums[i]/(mid*1.0));
            op--;
        }
        return op<=maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,maxOperations)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};