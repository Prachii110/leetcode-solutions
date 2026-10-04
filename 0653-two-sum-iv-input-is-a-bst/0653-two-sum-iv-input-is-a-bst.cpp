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

    bool search(TreeNode* root,int val,TreeNode* current)
    {
        if(root==NULL)
        return false;

        if(root->val==val && root!=current)
        return true;
        else if(root->val > val)
        return search(root->left,val,current);
        else 
        return search(root->right,val,current);

    }

    bool Target(TreeNode *root,int k,TreeNode* original)
    {
        if(root==NULL)
        return false;

        if(k-root->val != root->val)
        if(search(original,k-root->val,root))
        return true;

        return Target(root->left,k,original) || Target(root->right,k,original);

    }
    bool findTarget(TreeNode* root, int k) {

      return Target(root,k,root);
        
    }
};