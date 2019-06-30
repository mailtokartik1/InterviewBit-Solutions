/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A) {
    if (A == NULL) {
        return 0;
    }
    return 1 + max(height(A -> left), height(A -> right));
}
void getLevelOrderTraversal(TreeNode* A, vector<vector<int> > &B, int index) {
    if (A == NULL) {
        return;
    }
    B[index].push_back(A -> val);
    getLevelOrderTraversal(A -> left, B, index + 1);
    getLevelOrderTraversal(A -> right, B, index + 1);
    return;
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > B(height(A));
    getLevelOrderTraversal(A, B, 0);
    bool flag = false;
    for (int i = 0; i < B.size(); i ++) {
        if (flag) {
            reverse(B[i].begin(), B[i].end());  
        }
        flag = !flag;
    }
    return B;
}
