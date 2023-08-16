class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL)
            return false;
        if(q == NULL)
            return false;
        
        if(p->val == q->val)
        {
            bool left = isSameTree(p->left,q->left);
            bool right =isSameTree(p->right,q->right);
            
            if(left && right)
                return true;
            else
                return false;
        }
        else
            return false;  
    }
};