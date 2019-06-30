/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findTail(TreeNode* A) {
    if (A == NULL) {
        return A;
    }
    if (A -> right == NULL) {
        return A;
    }
    return findTail(A -> right);
}
TreeNode* findRight(TreeNode* A) {
    if (A == NULL) {
        return A;
    }
    if (A -> right == NULL) {
        return A;
    }
    return findRight(A -> right);
}
TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL) {
        return NULL;
    }
    TreeNode* temp = A -> right;
    A -> right = flatten(A -> left);
    TreeNode* temp1 = findTail(A -> right);
    A -> left = NULL;
    if (temp1) {
        temp1 -> right = flatten(temp);    
    } else {
        A -> right = flatten(temp);
    }
    return A;
}
