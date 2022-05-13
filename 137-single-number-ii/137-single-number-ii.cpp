class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>arr(32,0);
        for(int i=0;i<nums.size();i++){
            
            for(int j=0;j<32;j++){
                if((nums[i]>>j)&1){
                    arr[j]++;
                }
            }
        }
        int ans= 0;
        for(int i=0;i<32;i++){
            
            if(arr[i]%3 == 1){
               ans+= 1<<i;
            }
        }
        return ans;
    }
};