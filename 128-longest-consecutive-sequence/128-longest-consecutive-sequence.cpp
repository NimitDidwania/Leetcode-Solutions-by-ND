class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size() , ans =0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)s.insert(nums[i]);
        for(auto y:s){
            int x=y;
            while(s.find(x-1) != s.end())x--;
            int curr=0;
            while(s.find(x)!=s.end()){
                curr++;
                if(x!=y)
                s.erase(x);
                x++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};