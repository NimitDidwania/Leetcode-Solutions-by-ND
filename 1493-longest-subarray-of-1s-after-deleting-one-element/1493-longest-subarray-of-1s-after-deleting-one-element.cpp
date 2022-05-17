class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
       int s=0 , e=0 , n=nums.size() , z=0 ,ans=0; 
        while(e<n){
            if(nums[e]==0)z++;
            while(s<e && z==2){
                if(nums[s]==0)z--;
                s++;
            }
            ans = max(ans,e-s+1);
            e++;
        }
        return ans-1;
    }
};