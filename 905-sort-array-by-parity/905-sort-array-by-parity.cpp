class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=0 , n=nums.size();
        for(int i=0;i<n;i++){
            if(!(nums[i]&1))swap(nums[i],nums[j++]);
        }
        return nums;
    }
};