class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int> &inOrder){
        if(root==NULL){
            return;
        }

        inOrderTraversal(root->left,inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right,inOrder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        inOrderTraversal(root,inOrder);

        int i=0,j=inOrder.size()-1;

        while(i < j){
            int sum = inOrder[i] + inOrder[j];

            if(sum==k)
              return true;

            if(sum > k){
                j--;
            }

            else{
                i++;
            }
        }

        return false;
    }
};