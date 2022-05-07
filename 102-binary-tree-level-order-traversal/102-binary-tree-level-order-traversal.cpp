
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            auto curr = q.front();
            q.pop();
            if(curr==NULL){
                           q.push(NULL);
                           ans.push_back(level);
                           level.clear();
                           
                           continue;}
            level.push_back(curr->val);
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        ans.push_back(level);
        return ans;
    }
};