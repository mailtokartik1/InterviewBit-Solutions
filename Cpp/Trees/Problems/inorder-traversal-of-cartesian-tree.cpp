/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildCartesianTree(vector<int> &A, int start, int end) {
    if (start == end) {
        return new TreeNode(A[start]);
    } else if (start > end) {
        return NULL;
    }
    TreeNode* root = NULL;
    int index, maxi = INT_MIN;
    for (int i = start; i <= end; i ++) {
        if (A[i] > maxi) {
            index = i;
            maxi = A[i];
        }
    }
    root = new TreeNode(maxi);
    root -> left = buildCartesianTree(A, start, index - 1);
    root -> right = buildCartesianTree(A, index + 1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    if (A.size() <= 0) {
        return NULL;
    }
    return buildCartesianTree(A, 0, A.size() - 1);
}
