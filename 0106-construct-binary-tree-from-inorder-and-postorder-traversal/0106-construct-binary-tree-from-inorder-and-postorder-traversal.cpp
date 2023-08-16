class Solution {
public:
TreeNode* myfunc(int poststart,int postend,int instart,int inend,vector<int>& inorder,vector<int>& postorder,unordered_map<int,int>& inmap){
    if(poststart>postend || instart>inend) return NULL;
    TreeNode* root=new TreeNode(postorder[postend]);
    int inroot=inmap[root->val];
    int numsleft=inroot-instart;
    root->left=myfunc(poststart,poststart+numsleft-1,instart,inroot-1,inorder,postorder,inmap);
    root->right=myfunc(poststart+numsleft,postend-1,inroot+1,inend,inorder,postorder,inmap);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
        }
        return myfunc(0,n-1,0,n-1,inorder,postorder,inmap);
    }
};