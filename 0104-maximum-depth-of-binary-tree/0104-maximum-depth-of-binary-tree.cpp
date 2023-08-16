class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;

        else
        {
            int righth= maxDepth(root->right);
            int lefth= maxDepth(root->left);
            int ans= max(righth,lefth)+1;
            return ans;
        }
        
    }
};