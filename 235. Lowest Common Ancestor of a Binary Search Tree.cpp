class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        if(root==p || root==q)
            return root;
        TreeNode* lca1=lowestCommonAncestor(root->left,p,q);
        TreeNode* lca2=lowestCommonAncestor(root->right,p,q);
        if(lca1 && lca2)
            return root;
        if(lca1)
            return lca1;
        if(lca2)
            return lca2;
        return NULL;
    }
};
