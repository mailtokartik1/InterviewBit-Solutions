/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
int height(TreeLinkNode* A) {
    if (A == NULL) {
        return 0;
    }
    return 1 + max(height(A -> left), height(A -> right));
}
void lOT(TreeLinkNode* A, vector<vector<TreeLinkNode*>> &B, int index) {
    if (A == NULL) {
        return;
    }
    B[index].push_back(A);
    lOT(A -> left, B, index + 1);
    lOT(A -> right, B, index + 1);
}
void Solution::connect(TreeLinkNode* A) {

    // Approach 1

    /*
    vector<vector<TreeLinkNode*> > B(height(A));
    lOT(A, B, 0);
    for (int i = 0; i < B.size(); i ++) {
        for (int j = 0; j < B[i].size() - 1; j ++) {
            B[i][j] -> next = B[i][j + 1];
        }
    }
    return;
    */

    // Approach 2

    queue<TreeLinkNode*> queue1;
    queue<TreeLinkNode*> queue2;
    stack<TreeLinkNode*> curLevel;
    stack<TreeLinkNode*> nextLevel;
    if (A == NULL) {
        return;
    }
    queue1.push(A);
    TreeLinkNode* temp = NULL;
    while (!queue1.empty()) {
       TreeLinkNode* temp1 = queue1.front();
       temp1 -> next = temp;
       temp = temp1;
       queue1.pop();
       if (temp1 -> right) {
           queue2.push(temp1 -> right);
       }
       if (temp1 -> left) {
           queue2.push(temp1 -> left);
       }
       if (queue1.empty()) {
           temp = NULL;
           queue1.swap(queue2);
       }
    }
    return;
}
