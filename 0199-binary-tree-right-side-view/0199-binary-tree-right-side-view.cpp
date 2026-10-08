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

    queue<TreeNode*>q;

    void helper(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
        return;

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* temp=q.front();

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

                if(size==0)
                ans.push_back(temp->val);

                q.pop();
            }
        }       
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        q.push(root);

        helper(root,ans);

        return ans;
        
    }
};