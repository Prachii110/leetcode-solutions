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

    void inorder(TreeNode* root,vector<int>&list)
    {
        if(root==NULL)
        return;

        inorder(root->left,list);

        list.push_back(root->val);

        inorder(root->right,list);
        
    }

    void merge(vector<int>&l1,vector<int>&l2,vector<int>&ans)
    {
        int i=0,j=0;

        while(i<l1.size() && j<l2.size())
        {
            if(l1[i] < l2[j])
            {
                ans.push_back(l1[i]);
                i++;
            }
            else
            {
                ans.push_back(l2[j]);
                j++;
            }
        }

        while(i<l1.size())
        {
            ans.push_back(l1[i]);
            i++;
        }

        while(j<l2.size())
        {
            ans.push_back(l2[j]);
            j++;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>l1;
        vector<int>l2;

        inorder(root1,l1);
        inorder(root2,l2);
        merge(l1,l2,ans);

        return ans;
    }
};