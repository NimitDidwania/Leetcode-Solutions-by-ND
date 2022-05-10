#define ll long long
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll exp =1;
        ll ans=0 , gap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ll no = (ll)nums[i];
             gap = no - exp ;
            if(gap==-1)continue;
            if(gap >=k){
                ans +=(ll) k*(k+1)/2;
                ans +=(ll) k*(exp-1);
                k=0;
                break;
            }
            else{
                ans += gap*(gap+1)/2;
                ans += gap*(exp-1);
                k-=gap;
            }
            exp = nums[i]+1;
        }
        if(k!=0){
            ans += (ll)k*(k+1)/2;
            ans+= (exp-1)*k;
        }
        return ans;
    }
};