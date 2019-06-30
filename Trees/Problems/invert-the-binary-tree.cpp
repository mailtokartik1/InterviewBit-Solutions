/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if (A == NULL) {
        return A;
    }
    TreeNode* tempL = invertTree(A -> left);
    TreeNode* tempR = invertTree(A -> right);
    A -> left = tempR;
    A -> right = tempL;
    return A;
}
