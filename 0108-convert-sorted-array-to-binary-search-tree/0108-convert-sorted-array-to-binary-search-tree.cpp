TreeNode* convert(vector<int> v,int l, int r)
{
    if(l>r) return NULL;
    int mid = (l+r)/2;
    TreeNode* root = new TreeNode(v[mid]);
    TreeNode* newleft = convert(v,l,mid-1);
    TreeNode* newright = convert(v,mid+1,r);
    root->left = newleft;
    root->right = newright;
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
};