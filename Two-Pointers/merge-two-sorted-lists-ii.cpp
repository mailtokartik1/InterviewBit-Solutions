void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C;

    // Since the lists are already sorted, we compare the corresponding elements
    // After reaching the end, we append the other list to the solution

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] > B[j]) {
            C.push_back(B[j]);
            j ++;
        } else if (B[j] > A[i]) {
            C.push_back(A[i]);
            i ++;
        } else {
            C.push_back(A[i]);
            C.push_back(B[j]);
            i ++;
            j ++;
        }
    }
    if (i == A.size() && j == B.size()) {
        
    } else if (i == A.size()) {
        for (; j < B.size(); j ++) {
            C.push_back(B[j]);
        }
    } else if (j == B.size()) {
        for (; i < A.size(); i ++) {
            C.push_back(A[i]);
        }
    }
    A = C;
}
