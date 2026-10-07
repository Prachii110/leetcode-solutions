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

    queue <TreeNode*> q;
    int maxi=INT_MIN;
    int ans=0;

    void helper(TreeNode* root,int& level)
    {
        vector<int>arr;

        if(root==NULL)
        return ;

        while(!q.empty())
        {
            int size=q.size();
            level++;      
            int sum=0;

        while(size--)
        {    
            TreeNode* temp=q.front();

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);

            sum=sum+temp->val;      

            q.pop();
        }

        int tmp=maxi;
        maxi=max(maxi,sum); 

        if(tmp!=maxi)
        ans=level;
        }

    }

    int maxLevelSum(TreeNode* root) {
        int level=0;
        q.push(root);

        helper(root,level);

        return ans;
    }
};