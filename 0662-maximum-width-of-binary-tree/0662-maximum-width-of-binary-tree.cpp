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
    long long left=0,right=0;

    int maxWidth=0;

    queue<pair<TreeNode*,long long>>q;

    void width(TreeNode* root)
    {
        if(root==NULL)
        return;

        while(!q.empty())
        {
            int size=q.size();

            left=q.front().second;
            
            while(size--)
            {

                TreeNode* temp=q.front().first;   // node
                long long i=q.front().second-left;// to retreive the index value

                q.pop();

                if(temp->left)
                {
                    q.push({temp->left,2*i+1});   //pushing the nodes with their indexes
                    // left=2*i+1;
                }
                
                if(temp->right)
                {
                    q.push({temp->right,2*i+2});
                    // right=2*i+2;
                }

                if(size==0)
                right=i;
                                            
            }

            int curr=right+1;
            maxWidth=max(curr,maxWidth);   
        }

    }

    int widthOfBinaryTree(TreeNode* root) {
        q.push({root,0});
        width(root);

        return maxWidth;
    }
};