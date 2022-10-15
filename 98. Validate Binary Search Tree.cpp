class Solution {
public:
    static bool valid(TreeNode* root,long long Left,long long Right){
        if(root==NULL){
            return true;
        }
        if(root->val<=Left || root->val>=Right){
            return false;
        }
        return valid(root->left,Left,root->val) && valid(root->right,root->val,Right);
        
        
        
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return valid(root,-3147483648,3147483647);
        
        
    }
};
