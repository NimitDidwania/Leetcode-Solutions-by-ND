class MyStack {
private:
    queue<int>a,b;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(!a.empty())
        {
            b.push(x);
        while(!a.empty()){
            int x = a.front();
            a.pop();
            b.push(x);
        }
        
        }
        else{
            a.push(x);
            while(!b.empty()){
            int x = b.front();
            b.pop();
            a.push(x);
        }
        
        }
        }
    
    
    int pop() {
        if(a.empty()){
            int x=b.front();
            b.pop();
            return x;
        }
        else{
            int x=a.front();
            a.pop();
            return x;
        }
    }
    
    int top() {
        return a.empty() ? b.front() : a.front();
    }
    
    bool empty() {
        return a.empty() && b.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */