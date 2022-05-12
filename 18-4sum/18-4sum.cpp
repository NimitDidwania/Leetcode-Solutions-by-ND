class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        vector<vector<int>>ans;
        if(n<4)return ans;
        int prevFirst =nums[0]-1 ,prevSecond ;
        for(int i=0;i<n;){
            
            for(int j=i+1;j<n;){
                
                int x = target - nums[i] - nums[j] ;
                int low =j+1 , high =n-1;
                while(low<high){
                    int curr = nums[low] + nums[high];
                    int currLow = low;
                    
                    if(curr == x ){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                         high-- ;
                        while( low<high && nums[low]==nums[currLow])low++;
                    }
                    else if(curr>x)high--;
                    else low++;  
                }
                int k = j;
                while(k<n&&nums[j]==nums[k]){k++;}
                j=k;
            }
            int k=i;
            while(k<n &&nums[k]==nums[i])k++;
            i=k;
            
        }
        return ans;
    }
};