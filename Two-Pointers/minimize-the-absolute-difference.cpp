int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int mini = INT_MAX;

    // We use 3 pointers to keep track of the pointers
    // We match the corresponding elements on the lists
    // and increment the smallest one

    while (i < A.size() && j < B.size() && k < C.size()) {
        int diff = abs(max(max(A[i], B[j]), C[k]) - min(min(A[i], B[j]), C[k]));
        if (diff < mini) {
            mini = diff;
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
