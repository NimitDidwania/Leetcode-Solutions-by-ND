class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size() , ind=n-2;
        while(ind>=0 && nums[ind]>=nums[ind+1])ind--;
        if(ind==-1)reverse(nums.begin(),nums.end());
        else{
            // cout<<ind<<endl;
            for(int i=n-1;i>ind;i--){
                if(nums[ind]<nums[i]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
             sort(nums.begin()+ind+1,nums.end());
        }
       
    }
};