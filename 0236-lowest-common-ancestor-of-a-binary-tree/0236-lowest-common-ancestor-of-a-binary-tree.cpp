class Solution {

private:
    bool findN(TreeNode* node, vector<TreeNode*>& par, TreeNode* toFind){
        if(node == NULL){
            return false;
        }
        par.push_back(node);
        if(node==toFind){
            return true;
        }
        bool foundL = findN(node->left, par,toFind);
        if(foundL) return true;
        bool foundR = findN(node->right, par,toFind);
        if(foundR) return true;

        par.pop_back();
        return false;

    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> parQ;
        vector<TreeNode*> parP;
        bool foundP = findN(root, parP, p);
        bool foundQ = findN(root, parQ, q);
        TreeNode* currP;
        if (foundP && foundQ){
            for(int i = 0; i< min(parP.size(),parQ.size());++i){
                if(parP.at(i) == parQ.at(i)){
                    currP = parP.at(i);
                }
            }
            return currP;
        }

        return NULL;
    }

};