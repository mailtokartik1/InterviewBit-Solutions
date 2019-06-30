/**
    * Definition for binary tree
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
/*
int findIndex(vector<int> &B, int temp, int start, int end) {
    for (int i = start; i <= end; i ++) {
        if (B[i] == temp) {
            return i;
        }
    }
    return -1;
}
*/
TreeNode* build(vector<int> &A, vector<int> &B, int start, int end, int &index, unordered_map<int, int> &map) {
    if (start > end) {
        return NULL;
    }
    TreeNode* root = new TreeNode(A[index ++]);
    if (start == end) {
        return root;
    }
    int index1 = map[root -> val];
    root -> left = build(A, B, start, index1 - 1, index, map);
    root -> right = build(A, B, index1 + 1, end, index, map);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if (A.size() == 0 || B.size() == 0) {
        return NULL;
    }
    if (A.size() != B.size()) {
        return NULL;
    }
    unordered_map<int, int> map;
    for (int i = 0; i < B.size(); i ++) {
        map[B[i]] = i;
    }
    int index = 0;
    return build(A, B, 0, A.size() - 1, index, map);
}
