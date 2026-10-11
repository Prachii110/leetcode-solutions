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
    
    int sum=0;

    void revInorder(TreeNode* root)  // because reverse of inorder of a BST gives the values in decresing order
    {
        if(root==NULL)
        return ;

        revInorder(root->right);

        sum = sum + root -> val;
        root -> val = sum;
        

        revInorder(root->left); 

    }

    TreeNode* bstToGst(TreeNode* root) {
        revInorder(root);

        return root;
    }
};