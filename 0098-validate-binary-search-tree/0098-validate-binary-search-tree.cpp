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

 // we will check for every node , if it is a left node value than its value could be anything but less than root value and for right child should be greater than root value
class Solution {
public:

    bool valid(TreeNode* root,TreeNode* max,TreeNode* min)
    {
        if(root==NULL)
        return true;

        if(max!=NULL && root->val >= max->val)
        return false;

        if(min!=NULL && root->val <= min->val)
        return false;

        return valid(root->left,root,min) && valid(root->right,max,root);

    }

    bool isValidBST(TreeNode* root) {
        return valid(root,NULL,NULL);
        
    }
};