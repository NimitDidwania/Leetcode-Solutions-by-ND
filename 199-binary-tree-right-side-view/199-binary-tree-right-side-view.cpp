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
    int maxLevel=-1;
    void fun(TreeNode* root,vector<int>&ans,int level){
        if(root==NULL)return;
        if(level>maxLevel){ans.push_back(root->val);maxLevel = level;}
        fun(root->right,ans,level+1);
        fun(root->left,ans,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        maxLevel=-1;
        fun(root,ans,0);
        return ans;
    }
};