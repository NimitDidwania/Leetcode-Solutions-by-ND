class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                int sum=nums[a]+nums[b];
                int low=b+1,high=n-1;
                int ind=-1;
                while(low<=high)
                {
                    int mid= low+(high-low)/2;
                    if(nums[mid]<sum)ind=mid,low=mid+1;
                    else high=mid-1;
                }
                if(ind!=-1)ans+=(ind-b);
            }
        }
        return ans;
    }
};