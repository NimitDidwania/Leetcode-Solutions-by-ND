class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            int stop=pq.top();
            pq.pop();
            pq.push(abs(top-stop));
        }
        return pq.top();
    }
};