/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define DIVI 1003
int sumNum(TreeNode* A, int temp) {
    if (A == NULL) {
        return 0;
    }
    temp = (temp % DIVI) * 10;
    temp = ((temp % DIVI) + A -> val) % 1003;
    if (A -> left == NULL && A -> right == NULL) {
        int total = temp % DIVI;
        return total % DIVI;
    }
    int total = (sumNum(A -> left, temp)) % DIVI + (sumNum(A -> right, temp)) % DIVI;
    return total % DIVI;
}
int Solution::sumNumbers(TreeNode* A) {
    return sumNum(A, 0) % DIVI;
}
