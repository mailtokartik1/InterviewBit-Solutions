/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrder(TreeNode *A, vector<int> &temp) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left, temp);
    temp.push_back(A -> val);
    inOrder(A -> right, temp);
    return;
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> B;
    inOrder(A, B);
    int first = -1, second = -1;
    int i = 0;
    for (i = 0; i < B.size() - 1; i ++) {
        if (B[i + 1] < B[i]) {
            second = B[i];
            break;
        }
    }
    for (i = B.size() - 1; i >= 1; i --) {
        if (B[i - 1] > B[i]) {
            first = B[i];
            break;
        }
    }
    vector<int> temp = {first, second};
    return temp;
}
