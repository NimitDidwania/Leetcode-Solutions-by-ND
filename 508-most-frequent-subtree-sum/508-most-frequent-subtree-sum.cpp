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
int x=0;
class Solution {
    int fun(TreeNode *root , unordered_map<int,int>&s){
        if(root==NULL){return 0;}
        
        int ans=0;
        int left = fun(root->left,s);
        int right = fun(root->right,s);
        if(root->left){
            s[left]++;
            
        }
        if(root->right){ 
            s[right]++;
            
        }
        return left+right+root->val;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>s;
        s[fun(root,s)]++;
        if(s[0]==0)s.erase(0);
        int mx=0;
        for(auto x:s){
            mx=max(mx,x.second);
            cout<<x.first<<" "<<x.second<<endl;
        }
        vector<int>ans;
        for(auto x:s){
            if(x.second == mx )ans.push_back(x.first);
        }
        return ans;
    }
};