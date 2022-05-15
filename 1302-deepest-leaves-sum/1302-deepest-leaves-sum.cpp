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
    
    
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            
             ans=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                ans+=curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return ans;
    }
};