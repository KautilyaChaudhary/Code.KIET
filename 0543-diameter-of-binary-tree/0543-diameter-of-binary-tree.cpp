class Solution {
public:
   int height(TreeNode* root)
	{
		if(root == nullptr)
		{
			return 0;
		}
			
		return 1 + max(height(root->left), height(root->right));
	}
    int d = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
        {
            return 0;
        }


        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        d = max(d, height(root->left) + height(root->right));


        return d;
        
    }
};