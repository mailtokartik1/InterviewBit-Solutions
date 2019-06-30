/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> temp;
    if (A == NULL) {
        return temp;
    }
    s.push(A);
    while (!s.empty()) {
        TreeNode* node = s.top();
        if (node -> left) {
            s.push(node -> left);
            node -> left = NULL;
        } else {
            temp.push_back(node -> val);
            s.pop();
            if (node -> right) {
                s.push(node -> right);
            }    
        }
    }
    return temp;
}
