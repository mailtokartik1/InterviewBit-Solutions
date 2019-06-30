/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > B;
    if (A == NULL) {
        return B;
    }
    map<int, vector<int>> mapp;
    queue<pair<TreeNode*, int>> queue;
    int level = 0;
    queue.push(make_pair(A, level));
    while (!queue.empty()) {
        pair<TreeNode*, int> temp = queue.front();
        queue.pop();
        mapp[temp.second].push_back(temp.first -> val);
        if (temp.first -> left) {
            queue.push(make_pair(temp.first -> left, temp.second - 1));
        }
        if (temp.first -> right) {
            queue.push(make_pair(temp.first -> right, temp.second + 1));
        }
    }
    B.resize(mapp.size());
    int i = 0;
    for (map<int, vector<int>>::iterator it = mapp.begin(); it != mapp.end(); it ++) {
        B[i] = it -> second;
        i ++;
    }
    return B;
}
