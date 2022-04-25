class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int s=0 , e=0 , n=nums.size();
        unordered_set<int>present;
        for(int i=0;i<n;i++){
            if(present.size()== k+1){
                present.erase(nums[s++]);
            }
            
            if(present.find(nums[i])!=present.end())return 1;
            else present.insert(nums[i]);
        }
        return 0;
    }
};