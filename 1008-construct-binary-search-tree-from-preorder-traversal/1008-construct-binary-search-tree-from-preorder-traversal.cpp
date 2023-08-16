class Solution {
public:
    void helper(TreeNode* root,int value)
    {
        if(root == NULL)
        {
            return ;
        }
        if(value > root->val && root->right == NULL)
        {
            TreeNode* cur = new TreeNode(value) ;
            root->right   = cur  ;
            return ;
        }
        if(value < root->val && root->left == NULL)
        {
            TreeNode* cur = new TreeNode(value) ;
            root->left = cur ;
            return ;
        }
        if(value > root->val)
        {
            helper(root->right,value) ;
        }
        if(value < root->val) 
        {
            helper(root->left,value) ;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0 ;
        TreeNode* root = NULL ;
        TreeNode* temp ;
        for(int i=0;i<preorder.size();i++)
        {
            if(root == NULL)
            {
                root = new TreeNode(preorder[i]) ;
                temp = root ;
            }
            else if(preorder[i] < root->val)
            {
                TreeNode* cur = new TreeNode(preorder[i]) ;
                root->left    = cur ;
                root          = root->left ;
            }
            else
            {
                index = i ;
                break ;
            }
        }
        root = temp ;vector<int> rem ;
        if(index == 0){
            return root ;
        }
        rem.push_back(preorder[index]) ;
        for(int i=index;i<preorder.size();i++)
        {
         int data = preorder[i] ;
         if(data > root->val)
         {
             TreeNode* cur = new TreeNode(data) ;
             root->right   = cur ;
             root          = root->right ;
         }
         else
         {
             rem.push_back(preorder[i]) ;
         }
        }
        root = temp ;
        for(auto x: rem)
        {
            helper(root,x) ;
        }
        return root ;
    }
};