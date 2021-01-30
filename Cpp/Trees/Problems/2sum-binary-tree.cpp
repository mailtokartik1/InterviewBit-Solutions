/**
    * Definition for binary tree
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
void inOrder(TreeNode* A, vector<int> &temp) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left, temp);
    temp.push_back(A -> val);
    inOrder(A -> right, temp);
    return;
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> temp;
    inOrder(A, temp);
    int i = 0;
    int j = temp.size() - 1;
    while (i < j) {
        if (temp[i] + temp[j] == B) {
            return 1;
        } else if (temp[i] + temp[j] < B) {
            i ++;
        } else if (temp[i] + temp[j] > B) {
            j --;
        }
    }
    return 0;
}

