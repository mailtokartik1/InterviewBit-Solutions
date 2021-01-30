/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> B;
TreeNode* findMin(TreeNode* A) {
    if (A == NULL) {
        return NULL;
    }
    while (A -> left) {
        A = A -> left;
    }
    return A;
}
TreeNode* findCur(TreeNode* A, int B) {
    if (A == NULL) {
        return NULL;
    }
    if (A -> val == B) {
        return A;
    } else if (A -> val > B) {
        return findCur(A -> left, B);
    } else {
        return findCur(A -> right, B);
    }
    return NULL;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int C) {
    TreeNode* cur = findCur(A, C);
    if (cur == NULL) {
        return NULL;
    }
    if (cur -> right != NULL) {
        TreeNode* temp = cur -> right;
        return findMin(temp);
    }
    else {
        TreeNode* ancestor = A;
        TreeNode* successor = NULL;
        while (ancestor != cur) {
            if (cur -> val < ancestor -> val) {
                successor = ancestor;
                ancestor = ancestor -> left;
            } else {
                ancestor = ancestor -> right;
            }
        }
        return successor;
    }
    
    return A;
}