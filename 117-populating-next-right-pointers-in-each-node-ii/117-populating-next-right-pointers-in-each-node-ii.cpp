class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        Node* prev = NULL;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(prev!=NULL){
                prev->next = curr;
            }
            prev = curr;
            if(curr==NULL){
                if(prev!=NULL)
                prev->next = curr;
                if(q.size()==0)break;
                q.push(NULL);
                continue;
            }
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        return root;
    }
};