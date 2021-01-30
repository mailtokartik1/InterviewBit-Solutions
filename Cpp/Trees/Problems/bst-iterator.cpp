/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> temp;
bool isEmpty = false;
vector<int>::iterator it;
void inOrder(TreeNode* A) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left);
    temp.push_back(A -> val);
    inOrder(A -> right);
    return;
}
BSTIterator::BSTIterator(TreeNode *root) {
    temp.clear();
    inOrder(root);
    if (temp.size()) {
        isEmpty = false;
        it = temp.begin();
    } else isEmpty = true;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if (isEmpty) {
        return 0;
    } else {
        if (it != temp.end()) {
            return 1;
        }
        return 0;    
    }
}

/** @return the next smallest number */
int BSTIterator::next() {
    if (isEmpty) {
        return -1;
    } else {
        if (it != temp.end()) {
            int temp1 = *it;
            it ++;
            return temp1;
        } else {
            return -1;
        }    
    }
}
