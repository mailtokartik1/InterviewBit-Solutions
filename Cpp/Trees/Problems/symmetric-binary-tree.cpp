/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isIdentical(TreeNode* A, TreeNode* B) {
    if (A == NULL && B == NULL) {
        return 1;
    } else if (A == NULL || B == NULL) {
        return 0;
    }
    if (A -> val == B -> val && isIdentical(A -> left, B -> right) && isIdentical(A -> right, B -> left)) {
        return 1;
    }
    return 0;
}
int Solution::isSymmetric(TreeNode* A) {
    if (A == NULL) {
        return 1;
    }
    TreeNode* node = A;
    return isIdentical(A, A);
}
