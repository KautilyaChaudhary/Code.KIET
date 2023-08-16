class Solution {
public:
    class BSTInfo {
    public:
        bool isBST;
        int sum;
        int minVal;
        int maxVal;

        BSTInfo(bool bst, int s, int minv, int maxv)
        { 
            this->isBST=bst; 
            this->sum=s; 
            this->minVal=(minv);
            this->maxVal=(maxv);
        }
    };

    BSTInfo check(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return BSTInfo(true, 0, INT_MAX, INT_MIN);
        }

        BSTInfo left = check(root->left, maxSum);
        BSTInfo right = check(root->right, maxSum);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int sum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, sum);
            int minVal = min(left.minVal, root->val);
            int maxVal = max(right.maxVal, root->val);
            return BSTInfo(true, sum, minVal, maxVal);
        }

        return BSTInfo(false, 0, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        check(root, maxSum);
        return maxSum;
    }
};
