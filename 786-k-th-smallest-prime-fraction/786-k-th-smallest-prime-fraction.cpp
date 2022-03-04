#define info pair<double,pair<int,int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
          vector<info>v;
          int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                v.push_back({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        priority_queue<info>pq;
        for(info x:v)
        {
            if(pq.size()<k)
                pq.push(x);
            else{
                if(pq.top().first > x.first){
                    pq.pop();pq.push(x);
                }
            }
        }
        vector<int>ans;
        ans.push_back(pq.top().second.first);ans.push_back(pq.top().second.second);
        return ans;
    }
};