/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool pathSum(TreeNode* A, int curSum, int target) {
    if (A == NULL) {
        return 0;
    }
    if (A -> left == NULL && A -> right == NULL) {
        return curSum + A -> val == target;
    }
    return (pathSum(A -> left, A -> val + curSum, target) || pathSum(A -> right, A -> val + curSum, target));
}
int Solution::hasPathSum(TreeNode* A, int B) {
    if (A == NULL) {
        return 0;
    }
    return pathSum(A, 0, B);
}
