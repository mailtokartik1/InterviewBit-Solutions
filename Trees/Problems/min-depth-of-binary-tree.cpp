/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if (A == NULL) {
        return 0;
    }
    if (A -> left == NULL && A -> right == NULL) {
        return 1;
    }
    if (!A -> left) {
        return 1 + minDepth(A -> right);
    }
    if (!A -> right) {
        return 1 + minDepth(A -> left);
    }
    return (1 + min(minDepth(A -> left), minDepth(A -> right)));
}
