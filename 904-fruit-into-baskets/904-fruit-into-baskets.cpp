class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int s=0,e=0,n=fruits.size(),ans=0;
        unordered_map<int,int>mp;
        while(e<n){
            mp[fruits[e]]++;
            while(s<n && mp.size()==3){
                mp[fruits[s]]--;
                if(mp[fruits[s]]==0)mp.erase(fruits[s]);
                s++;
            }
            ans = max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};