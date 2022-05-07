
class Solution {
public:
    void fun(TreeNode *root,vector<int>&ans){
        if(root==NULL)return;
        
        ans.push_back(root->val);
        fun(root->left , ans);
        fun(root->right , ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        fun(root,ans);
        return ans;
    }
};