/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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