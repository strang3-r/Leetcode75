/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * f(vector<int> & preorder, int preS, int preE, vector<int> & inorder, int inS, int inE, map<int,int> &inMap){
        if(preS> preE || inS> inE)
            return NULL;
        
        TreeNode * root= new TreeNode(preorder[preS]);
        int inRoot= inMap[root->val];
        int pos=inRoot-inS;
        
        root->left=f(preorder, preS+1, preS+pos, inorder, inS, inRoot-1, inMap);
        root->right=f(preorder, preS+pos+1, preE, inorder, inRoot+1, inE, inMap);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode * root=f(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,inMap);
        
        return root;
    }
};