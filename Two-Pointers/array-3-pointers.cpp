int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int mini = INT_MAX;

    // Do exactly what is told and increment the pointer with minimum value

    while (i < A.size() && j < B.size() && k < C.size()) {
        if (max(max(abs(A[i] - B[j]), abs(B[j] - C[k])), abs(C[k] - A[i])) < mini) {
            mini = max(max(abs(A[i] - B[j]), abs(B[j] - C[k])), abs(C[k] - A[i]));
        }
        if (A[i] == min(min(A[i], B[j]), C[k])) {
            i ++;
        } else if (B[j] == min(min(A[i], B[j]), C[k])) {
            j ++;
        } else if (C[k] == min(min(A[i], B[j]), C[k])) {
            k ++;
        }
    }
    return mini;
}
