class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int s=0 , e=0 , n=nums.size(),ans=0;
        for(e=0;e<n;e++){
            if(nums[e]==0)k--;
            while(k<0 && s<e){
                if(nums[s]==0)k++;
                s++;
            }
            if(k>=0)
            ans = max(ans,e-s+1);
        }
        return ans;
    }
};