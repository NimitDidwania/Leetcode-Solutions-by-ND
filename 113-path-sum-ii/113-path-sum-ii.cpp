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
    void fun(TreeNode* root,int target,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(root==NULL)return;
        if(root->left==NULL&&
           root->right==NULL&&
           target==root->val){
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        fun(root->left,target-root->val,curr,ans);
        fun(root->right,target-root->val,curr,ans);
        curr.pop_back();
            
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        fun(root,targetSum,curr,ans);
        return ans;
    }
};