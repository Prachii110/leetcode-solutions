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
    
    void inorder(TreeNode* root,TreeNode* &prev,int &mindiff)
    {
        if(root==NULL)
        return;

        inorder(root->left,prev,mindiff);

        if(prev!=NULL)
        mindiff=min(mindiff,(root->val-prev->val));   

       prev=root;   


        inorder(root->right,prev,mindiff);

    }

    int minDiffInBST(TreeNode* root) {

        TreeNode* prev=NULL;
        int minDiff = INT_MAX;

        inorder(root, prev, minDiff);

        return minDiff;  

    }
};