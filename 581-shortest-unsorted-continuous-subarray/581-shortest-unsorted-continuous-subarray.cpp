class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>help = nums;
        sort(nums.begin(),nums.end());
        int low=0 , high = nums.size()-1;
        while( low<=high && (nums[low]==help[low]  || nums[high]==help[high] ) ){
            if(nums[low]==help[low])low++;
            if(nums[high]==help[high])high--;
        }
        int ans = high - low + 1;
        return ans==-1? 0:ans ;
    }
};