/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxi = 0;
int Solution::maxDepth(TreeNode* A) {
    if (A == NULL) {
        return 0;
    }
    if (A -> left == NULL && A -> right == NULL) {
        return 1;
    } else {
        int maxim = max(maxDepth(A -> left), maxDepth(A -> right));
        maxi = maxim + 1;    
    }
    return maxi;
}
