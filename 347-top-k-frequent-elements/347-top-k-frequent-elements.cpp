class Solution {
public:
    
    struct mycomp{
        bool operator()(pair<int,int> &m1, pair<int ,int> &m2)
        {
            return m1.second > m2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int , int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int , int> , vector<pair<int,int>> , mycomp>pq;
        int i=0;
        for(auto x:m)
        {
            
            if(i<k)
            {
                pq.push(x);
            }
            else
            {
                if(pq.top().second < x.second)
                {
                    pq.pop();
                    pq.push(x);
                }
            }
            i++;
        }
        vector<int>ans;
        while(!pq.empty())
        {
            
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
        
    }
};