/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrder(TreeNode* A, vector<int> &temp) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left, temp);
    temp.push_back(A -> val);
    inOrder(A -> right, temp);
    return;
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> temp;
    inOrder(A, temp);
    return temp[B - 1];
}
