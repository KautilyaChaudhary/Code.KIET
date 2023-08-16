class Codec {
public:

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    
    string s="";
    if(!root) return s;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
      TreeNode* curr = q.front();
      q.pop();

      if(curr == NULL)
         s.append("#,");
      else
          s.append(to_string(curr->val) + ',');

      if(curr)
      {
           q.push(curr->left);
           q.push(curr->right);
      }
      
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;

    stringstream s(data);  // using for break the string
    string str;
    getline(s,str,',');

    TreeNode* root = new TreeNode(stoi(str));  //convert str into integer
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        getline(s,str,',');
        if(str == "#")
        {
            temp->left = NULL;
        }
        else
        {
            TreeNode* leftnode = new TreeNode(stoi(str));
            temp->left = leftnode;
            q.push(leftnode);
        }

        getline(s,str,',');
        if(str == "#")
        {
            temp->right = NULL;
        }
        else
        {
            TreeNode* rightnode = new TreeNode(stoi(str));
            temp->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
};