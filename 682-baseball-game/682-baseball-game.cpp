class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0;
        stack<int>s;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int x=s.top();
                s.pop();
                int y=s.top();
                s.push(x);
                s.push(x+y);
            }
            else if(ops[i]=="D"){
                s.push(2*s.top());
            }
            else if(ops[i]=="C"){
                s.pop();
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};