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

    // largest value in the left subtree of the given node
    TreeNode* InprderPred(TreeNode* root)
    {
        if(root==NULL)
        return NULL;

        root=root->left;
        while(root->right)
        {
            root=root->right;
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;

        //leaf node
        if(root->right==NULL && root->left==NULL)
        {
            if(root->val==key)
            {
                delete root;
                return NULL;
            }
            
        }

        if(key > root->val)
        root->right=deleteNode(root->right,key);

        else if(key < root->val)
        root->left=deleteNode(root->left,key);

        else
        {
            //if only left child exist
            if(root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete root;

                return temp;
            }

             //if only right child exist
            if(root->left==NULL)
            {
                TreeNode* temp=root->right;
                delete root;

                return temp;
            }

            TreeNode *ipre=InprderPred(root);
            root->val=ipre->val;
            root->left=deleteNode(root->left,ipre->val);
        }

        return root;

        
    }
};