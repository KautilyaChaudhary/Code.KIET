class Solution {
public:

    int kthSmallest(TreeNode* root, int& k) {
    // Base case: if root is null or k is less than 0, return a large value
    if (root == nullptr || k < 0) {
        return 1e5;
    }

    int ans = 1e5;

    // Recursively find the kth smallest element in the left subtree
    ans = kthSmallest(root->left, k);

    // Decrement k by 1 as we have found one smaller element
    k--;

    // If k becomes 0, the current root is the kth smallest element
    if (k == 0) {
        return root->val;
    }

    // If the kth smallest element is not found in the left subtree,
    // recursively find it in the right subtree
    if (ans != 1e5) {
        return ans;
    }

    ans = kthSmallest(root->right, k);

    return ans;
}
};