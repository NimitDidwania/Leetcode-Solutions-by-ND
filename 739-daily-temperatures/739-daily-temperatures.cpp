class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n);
        ans[n-1]=-1;
        stack<int>s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            
            while(!s.empty() && temp[s.top()] <= temp[i])
                s.pop();
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1)ans[i]=0;
            else {
                ans[i] = ans[i] -i;
            }
        }
        return ans;
    }
};