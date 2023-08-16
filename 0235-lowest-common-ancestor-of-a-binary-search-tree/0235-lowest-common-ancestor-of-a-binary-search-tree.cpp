class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root ;
        }
        int temp=root->val ;
        int pval=p->val ;
        int qval=q->val ;

        if(temp>pval && temp>qval){
            return lowestCommonAncestor(root->left,p,q) ;
        }
        else if(temp<pval && temp<qval){
            return lowestCommonAncestor(root->right,p,q) ;
        }
        else{
            return root ;
        }
    }
};