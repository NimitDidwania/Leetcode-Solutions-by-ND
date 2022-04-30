class ProductOfNumbers {
    vector<int>pp;
    int prev;
    int lastZero;
public:
    ProductOfNumbers(){
        prev=1;
        lastZero=-1;
    }
    
    void add(int num) {
        
        pp.push_back(num*prev);
        if(num==0)prev=1,lastZero=pp.size()-1;
        else prev*=num;
    }
    
    int getProduct(int k) {
        int n=pp.size();
        int l = n-1 , s = n-k;
        if(lastZero>=s && lastZero<=l)return 0;
       int ans = (s==0 || pp[s-1]==0)? pp[n-1] :pp[n-1]/pp[s-1];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */