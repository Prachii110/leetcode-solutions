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

    void helper(TreeNode* root,int& ans)
    {
        if(root==NULL)
        return;

        while(!q.empty())
        {
            int size=q.size();

            // taking the first node
            ans=q.front()->val;
            while(size--)
            {
                TreeNode* temp=q.front();

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);              

                q.pop();
            }
        }  
    }

    int findBottomLeftValue(TreeNode* root) {
        q.push(root);

        int ans;

        helper(root,ans);

        return ans;
    }
};