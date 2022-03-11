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
    vector<TreeNode*>fun(int n){
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }
        if(n==3)
        {
            TreeNode* root=new TreeNode(0);
            root->left=new TreeNode(0);
            root->right=new TreeNode(0);
            return {root};
        }
        vector<TreeNode*>ans;
        
        for(int i=1;i<=n-1;i+=2){
           vector<TreeNode*>l=fun(i);
           
           vector<TreeNode*>r=fun(n-i-1);
           for(auto lft:l)
           {
               for(auto rgt:r)
               {
                   TreeNode* root=new TreeNode(0);
                   root->left=lft;
                   root->right=rgt;
                   ans.push_back(root);
               }
           }
        }
        return ans;
        }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};
        else return fun(n);
    }
};