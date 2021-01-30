/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preOrder(TreeNode* A) {
    if (A == NULL) {
        return;
    }
    cout << A -> val << " ";
    preOrder(A -> left);
    preOrder(A -> right);
}
void inOrder(TreeNode* A) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left);
    cout << A -> val << " ";
    inOrder(A -> right);
}
TreeNode* buildTree(const vector<int> &A, int start, int end) {
    TreeNode* root = NULL;
    if (start > end) {
        return NULL;
    }
    if (start <= end) {
        int mid = start + (end - start) / 2;
        root = new TreeNode(A[mid]);
        root -> left = buildTree(A, start, mid - 1);
        root -> right = buildTree(A, mid + 1, end);    
    }
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if (A.size() <= 0) {
        return NULL;
    }
    TreeNode* temp = buildTree(A, 0, A.size() - 1);
    return temp;
}
