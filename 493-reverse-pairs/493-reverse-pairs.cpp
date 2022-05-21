#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace __gnu_pbds;
  
#define pbds tree<ll, null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds a ;ll ans=0;
        for(int i=0;i<nums.size();i++){
             ans += a.order_of_key(2ll*nums[i]);
            a.insert(nums[i]);
        }
        return ans;
    }
};