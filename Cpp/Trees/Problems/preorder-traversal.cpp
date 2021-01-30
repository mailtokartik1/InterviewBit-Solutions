/**
    * Definition for binary tree
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> B;
    stack<TreeNode*> s;
    if (A == NULL) {
        return B;
    }
    s.push(A);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        B.push_back(node -> val);
        if (node -> right) {
            s.push(node -> right);
        }
        if (node -> left) {
            s.push(node -> left);
        }
    }
    return B;
}
