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
    void fun(TreeNode *root,int curr,int &ans){
        
        
        if(root==NULL){
            
            return;
        }
        if(root->left==NULL && root->right==NULL){
            int x=curr*10 + root->val;
            ans+=(x);
            return;
        }
        fun(root->left,curr*10 + root->val , ans);
        fun(root->right,curr*10 + root->val , ans);
        // cout<<a<<" "<<b<<endl;
        return ;
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0 , curr=0;
         fun(root,curr,ans);
        return ans;
    }
};