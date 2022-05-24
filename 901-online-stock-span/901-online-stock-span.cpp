class StockSpanner {
    stack<int>st;
    vector<int>v;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty()  && v[st.top()]<=price)st.pop();
        int ans =  v.size() ;
        if(!st.empty())ans-=(st.top()+1);
        int sz = v.size();
        st.push(sz-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */