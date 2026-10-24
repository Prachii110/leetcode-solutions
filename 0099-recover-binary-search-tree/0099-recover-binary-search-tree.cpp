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
    void recover(TreeNode* &root,TreeNode* &prev,TreeNode* &first,TreeNode* &end)
    {
        if(root==NULL)
        return;

        recover(root->left,prev,first,end);

        if(prev!=NULL && root->val  < prev->val)
        {
            if(first==NULL)
            first=prev;   // first is updated on only first violation

            end=root;  // end is updated on every violation
        }        

        prev=root;

        recover(root->right,prev,first,end);
    }
    

    void recoverTree(TreeNode* root) {
        TreeNode *first=nullptr,*end=nullptr,*prev=nullptr;
        recover(root,prev,first,end);

        if(first!=NULL && end!=NULL)
        swap(first->val , end->val);
    }
};