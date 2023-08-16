class Solution {
public:

   void dfs(Node *root,vector<Node *>&v,vector<bool>&vis)
   {
       vis[root->val]=true;
       if(!v[root->val])
       {
         Node *n=new Node(root->val);
         v[root->val]=n;
       }
       vector<Node *>v1;
       for(auto c:root->neighbors)
       {
           if(!vis[c->val])
           {
                dfs(c,v,vis);
               
           }
            v[root->val]->neighbors.push_back(v[c->val]);
       }
      
   }

    Node* cloneGraph(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        vector<Node *>v(101,NULL);
        vector<bool>vis(101,0);
        
        dfs(root,v,vis);
        return v[root->val];
    }
};
