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

    TreeNode* ans=new TreeNode(0);
    TreeNode* og=ans;

    void flatten(TreeNode* root) {

        if(root==NULL)
        return;

        TreeNode* left=root->left;
        TreeNode* right=root->right;

        ans->right=root;
        ans->left=NULL;
        ans=ans->right;

        flatten(left) ;
        flatten(right);   

        root=og->right;    
    }
};