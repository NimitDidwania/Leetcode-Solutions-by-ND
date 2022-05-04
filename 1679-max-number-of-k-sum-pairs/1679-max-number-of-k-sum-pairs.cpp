class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int search = k-nums[i];
            if(m.find(search)!=m.end()){
                m[search]--;
                ans++;
                if(m[search]==0)m.erase(search);
            }
            else m[nums[i]]++;
        }
        return ans;
    }
};