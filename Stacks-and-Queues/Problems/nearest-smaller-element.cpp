vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> B;
    vector<int> C;

    // Keep popping from the stack until a value smaller than A[i] is found or the stack is empty

    for (int i = 0; i < A.size(); i ++) {
        if (B.empty()) {
            C.push_back(-1);
            B.push(A[i]);
        } else {
            while (!B.empty() && B.top() >= A[i]) {
                B.pop();
            }
            if (B.empty()) {
                C.push_back(-1);
                B.push(A[i]);
            } else {
                C.push_back(B.top());
                B.push(A[i]);
            }
        }
    }
    return C;
}
