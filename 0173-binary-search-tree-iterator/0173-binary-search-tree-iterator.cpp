class BSTIterator {
public:
/////////////// The commented code is also right but after the function all the BST will be destroyed//////////////////////////
   stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        // st.push(root);
       while(root){
          st.push(root);
          root=root->left;
       }

    }
    
    int next() {
        // auto top=st.top();
        // st.pop();
        // if(top->left){
        //     st.push(top);
        //     st.push(top->left);
        //     int ret= next();
        //     top->left=nullptr;
        //     return ret;
        // }
        // int ret=top->val;
        
        // if(top->right)st.push(top->right);
        // return ret;

        auto top=st.top();
        st.pop();
        int ret=top->val;
        if(top->right){
            auto node= top->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
       return st.empty()==false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */