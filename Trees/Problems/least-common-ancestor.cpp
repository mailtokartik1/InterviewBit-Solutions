/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPathToNode(TreeNode* A, vector<int> temp, vector<vector<int> > &D, int C) {
    if (A == NULL) {
        return;
    }
    temp.push_back(A -> val);
    if (A -> val == C) {
        D.push_back(temp);
        return;
    }
    findPathToNode(A -> left, temp, D, C);
    findPathToNode(A -> right, temp, D, C);
    return;
}
int Solution::lca(TreeNode* A, int B, int C) {
    if (A == NULL) {
        return -1;
    }
    vector<vector<int> > D;
    vector<int> temp, temp2;
    findPathToNode(A, temp, D, C);
    findPathToNode(A, temp2, D, B);
    if (B == C) {
        if (D.size() == 0) {
            return -1;
        } else if (D.size() == 1) {
            return B;
        }
    }
    if (D.size() <= 1) {
        return -1;
    }
    int index = -1;
    int size = min(D[0].size(), D[1].size());
    for (int i = 0; i < size; i ++) {
        if (D[0][i] == D[1][i]) {
            index = D[0][i];
        } else {
            break;
        }
    }
    return index;
}
