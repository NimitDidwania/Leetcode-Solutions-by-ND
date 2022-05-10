class Solution {
public:
    int m = 1000000007;
  
    
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++){
            pq.push((long long)nums[i]);
        }
        while(k!=0){
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest+1);
            k--;
        }
        long long ans=1;
        while(!pq.empty()){
            int x = pq.top();pq.pop();
            ans = (ans*x)%m;
        }
        return (int)ans%m;
    }
};