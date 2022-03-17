/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root,unordered_map<TreeNode*,int>&m)
    {
        if(root==NULL)return 0;
        if(m[root]!=-1)return m[root];
        int first = root->val + ((root->left!=NULL)?
                    (fun(root->left->left,m) + fun(root->left->right,m)):0)
        + ((root->right!=NULL)?
                    (fun(root->right->left,m) + fun(root->right->right,m)):0) ;
        int second = fun(root->left,m) + fun(root->right,m);
        m[root]= max(first,second);
        return m[root];
    }
    void inorder(TreeNode*root,unordered_map<TreeNode*,int>&m)
    {
        if(root==NULL)return;
        inorder(root->left,m);
        m[root]=-1;
        inorder(root->right,m);
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>m;
        inorder(root,m);
        return fun(root,m);
    }
};