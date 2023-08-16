class Solution {
public:
    
    void solve(Node*&root)
    {
        if(root==NULL)
        return;

        if(root->left==NULL && root->right==NULL)
        return;
        
        root->left->next=root->right;
        if(root->next!=NULL)
        root->right->next=root->next->left;
        else
        root->right->next=NULL;

        solve(root->left);
        solve(root->right);

    }






    Node* connect(Node* root) {
        solve(root);
        return root;
        
    }
};