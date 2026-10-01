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

    bool tree(TreeNode* root,TreeNode* parent)
    {
        if(root==NULL)
        return false;

        if(root->left==NULL)
        if(root->val == 3)
        return (root->left->val && root->right->val);

        if(root->val == 2)
        return (root->left->val || root->right->val);

        return tree(root->left,root) && tree(root->right,root);
    }

    bool evaluateTree(TreeNode* root) {

        if(root==NULL)
        return false;

        if(root->left==NULL && root->right==NULL)
        {
            return root->val==1;

        }

        bool left=evaluateTree(root->left);
        bool right=evaluateTree(root->right);

        if(root->val==2)
        return left || right;

        return left && right;

        
    }
};