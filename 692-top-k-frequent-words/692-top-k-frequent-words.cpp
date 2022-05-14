#define info pair<int,string> 
struct comp {
    bool operator()(info a,info b )
    {
        if(a.first < b.first)return true;
        if(a.first == b.first){
            if(a.second > b.second)return true;
        }
        return false;
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
        priority_queue<info,vector<info>,comp>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        cout<<pq.top().first<<" "<<pq.top().second;
        vector<string>ans;
        int i=0;
        while(!pq.empty() && i!=k){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        // sort(ans.begin(),ans.end());
        return ans;
    }
};