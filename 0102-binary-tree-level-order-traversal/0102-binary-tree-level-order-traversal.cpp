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
    vector<vector<int>>ans;
    queue <TreeNode*> q;

    void BFS(TreeNode* root)
    {
        vector<int>arr;

        if(root==NULL)
        return;

        int size=q.size();
        while(size--)
        {
            TreeNode* temp=q.front();
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);

            arr.push_back(temp->val);
            q.pop();
        }

        if(!arr.empty())
        ans.push_back(arr);

        BFS(root->left);
        BFS(root->right);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
     
        q.push(root);

        BFS(root);

        return ans;

        
        
    }
};