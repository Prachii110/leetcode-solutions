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

    int left_height(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        return 1+left_height(root->left);
    }

    int right_height(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        return 1+right_height(root->right);
    }

    int countNodes(TreeNode* root) {

        if(root==NULL)
        return 0;

        if(left_height(root) == right_height(root))
        return pow(2,left_height(root)) - 1;

        return (1+countNodes(root->left)+countNodes(root->right));

        
    }
};