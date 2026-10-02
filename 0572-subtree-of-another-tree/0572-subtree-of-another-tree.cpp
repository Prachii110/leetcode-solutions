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

    bool isSameTree(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL && r2==NULL)
        return true;

        if(r1==NULL || r2==NULL)
        return false;

        if(r1->val == r2->val)
        {
            return isSameTree(r1->left,r2->left) && isSameTree(r1->right,r2->right); 
        }

        return false;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)
        return true;

        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL))
        return false;

        if(root->val==subRoot->val)
        {
            if(isSameTree(root,subRoot))  //if node value matches , but the tree are not same then keep on finding
            return true;
        }

        //check in left and right subtree that if subtree node value matches with any of the node in main tree
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};