/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &in, vector<int> &post, int start, int end, int &index, unordered_map<int, int> &map) {
    if (start > end) {
        return NULL;
    }
    TreeNode* root = new TreeNode(post[index ++]);
    if (start == end) {
        return root;
    }
    int index1 = map[root -> val];
    root -> right = build(in, post, start, index1 - 1, index, map);
    root -> left = build(in, post, index1 + 1, end, index, map);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    if (in.size() != post.size()) {
        return NULL;
    }
    if (in.size() == 0 || post.size() == 0) {
        return NULL;
    }
    reverse(post.begin(), post.end());
    reverse(in.begin(), in.end());
    unordered_map<int, int> map;
    for (int i = 0; i < in.size(); i ++) {
        map[in[i]] = i;
    }
    int index = 0;
    return build(in, post, 0, in.size() - 1, index, map);
}
