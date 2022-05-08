
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(level);
                level.clear();
                if(q.empty())break;
                q.push(NULL);
                continue;
            }
            level.push_back(curr->val);
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        return ans;
    }
};