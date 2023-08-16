class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue< TreeNode* >q;
        vector<vector<int>>ans;
        vector<int>tmp;

        int L=1;

        if(root==NULL)
            return ans;

        q.push(root);
        int c = 1;
        

        while(!q.empty()){
            tmp.clear();
            L=c;
            c = 0;
            for(int i=0;i<L;i++){

                TreeNode* k = q.front();
                q.pop();
                if (k) { 
                tmp.push_back(k->val);
                    if (k->left) {
                        q.push(k->left);
                        c++;
                    }
                    if (k->right) {
                        q.push(k->right);
                        c++;
                    }
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};