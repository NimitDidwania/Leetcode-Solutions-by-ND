struct Node{
    Node* links[10];
    bool last=false;
};

class Solution {
public:
    void fun(Node *node,int &curr,vector<int>&ans){
        if(node==NULL){
           
            return;
        }
        if(node->last){
            ans.push_back(curr);
        
        }
        for(int i=0;i<10;i++){
            if(node->links[i]){
                curr=curr*10 + i;
                fun(node->links[i],curr,ans);
                curr/=10;
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        Node *root = new Node();
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            Node *node=root;
            for(auto ch:s){
                if(node->links[ch-'0']==NULL){
                    Node *temp = new Node();
                    node->links[ch-'0']=temp;
                }
                node=node->links[ch-'0'];
            }
            node->last=true;
        }
        
        Node *node=root;
        int curr=0;
        vector<int>ans;
        fun(node,curr,ans);
        return ans;
    }
};