/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findSum(TreeNode* A, int B, vector<int> temp, vector<vector<int> > &C, int sum) {
    if (A == NULL) {
        return;
    }
    sum += A -> val;
    temp.push_back(A -> val);
    if (A -> left == NULL && A -> right == NULL) {
        if (sum == B) {
            C.push_back(temp);
        }
        return;
    }
    findSum(A -> left, B, temp, C, sum);
    findSum(A -> right, B, temp, C, sum);
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> temp;
    vector<vector<int> > C;
    findSum(A, B, temp, C, 0);
    return C;
}
