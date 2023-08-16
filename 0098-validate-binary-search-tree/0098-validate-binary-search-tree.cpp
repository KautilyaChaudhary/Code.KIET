#include <limits.h>
#include <stack>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root== NULL){
            return false;
        }
         
    stack<TreeNode*> s;
    TreeNode* curr = root;
    TreeNode* prev = NULL;

    while(curr != NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }else{
            curr = s.top();
            s.pop();
            if(prev != NULL && prev->val >= curr->val){
                return false;
            }
            prev = curr;
            curr = curr->right;
        }
    }
    return true;
    }
};