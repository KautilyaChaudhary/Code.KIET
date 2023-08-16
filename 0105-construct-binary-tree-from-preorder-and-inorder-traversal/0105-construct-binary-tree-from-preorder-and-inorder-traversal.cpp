class Solution {
public:
    TreeNode* solve(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int>& mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inStart;
        root->left = solve(preOrder, preStart+1, preStart+numsLeft, inOrder, inStart, inRoot-1, mp);
        root->right = solve(preOrder, preStart+1+numsLeft, preEnd, inOrder, inRoot+1, inEnd, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        int n = preOrder.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inOrder[i]] = i;
        }
        return solve(preOrder, 0, n-1, inOrder, 0, n-1, mp);
    }
};