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
#define VALID_MIN   -10000
#define VALID_MAX   10000
class Solution {
public:
    bool FindTargetTwo(struct TreeNode* pstLeft, struct TreeNode* pstRight, int nK)
{
    if(pstLeft->val + pstRight->val == nK) return true;

    if(pstLeft->val + pstRight->val > nK)
    {
        if(pstLeft->left && FindTargetTwo(pstLeft->left, pstRight, nK)) return true;

        if(pstRight->left && FindTargetTwo(pstLeft, pstRight->left, nK)) return true;
    }
    else
    {
        if(pstLeft->right && FindTargetTwo(pstLeft->right, pstRight, nK)) return true;

        if(pstRight->right && FindTargetTwo(pstLeft, pstRight->right, nK)) return true;
    }

    return false;
}

bool FindTargetOne(struct TreeNode* pstRoot, int nK)
{
    if(pstRoot->val == nK) return true;

    if(pstRoot->val > nK)
    {
        if(pstRoot->left && FindTargetOne(pstRoot->left, nK)) return true;
    }
    else
    {
        if(pstRoot->right && FindTargetOne(pstRoot->right, nK)) return true;
    }

    return false;
}

bool FindTargetInner(struct TreeNode* pstRoot, int nK, short sMin, short sMax)
{
    if(pstRoot->left == NULL && pstRoot->right == NULL) return false;

    // find minimum of input BST
    if(sMin < VALID_MIN)
    {
        struct TreeNode* pstTmp = pstRoot;
        while(pstTmp->left) pstTmp = pstTmp->left;
        sMin = pstTmp->val;
        if(nK <= sMin * 2) return false;
    }
    
    // check relation of pstRoot->val & sMin
    if(nK == pstRoot->val + sMin) return true;
    if(nK < pstRoot->val + sMin) return pstRoot->left && FindTargetInner(pstRoot->left, nK, sMin, SHRT_MAX);

    // find maximum of input BST
    if(sMax > VALID_MAX)
    {
        struct TreeNode* pstTmp = pstRoot;
        while(pstTmp->right) pstTmp = pstTmp->right;
        sMax = pstTmp->val;
        if(nK >= sMax * 2) return false;
    }

    // check relation of pstRoot->val & sMax
    if(nK == pstRoot->val + sMax) return true;
    if(nK > pstRoot->val + sMax) return pstRoot->right && FindTargetInner(pstRoot->right, nK, SHRT_MIN, sMax);

    // if one value is current root, check the other one
    if(nK < pstRoot->val * 2)
    {
        if(pstRoot->left)
        {
            if(FindTargetOne(pstRoot->left, nK-pstRoot->val)) return true;

            if(FindTargetInner(pstRoot->left, nK, sMin, SHRT_MAX)) return true;
        }
    }
    else if(nK > pstRoot->val * 2)
    {
        if(pstRoot->right)
        {
            if(FindTargetOne(pstRoot->right, nK-pstRoot->val)) return true;

            if(FindTargetInner(pstRoot->right, nK, SHRT_MIN, sMax)) return true;
        }
    }

    // check both left & right leaf
    return pstRoot->left && pstRoot->right && FindTargetTwo(pstRoot->left, pstRoot->right, nK);
}

bool findTarget(struct TreeNode* root, int k){
    return FindTargetInner(root, k, SHRT_MIN, SHRT_MAX);
}
};
