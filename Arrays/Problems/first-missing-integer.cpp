int Solution::firstMissingPositive(vector<int> &A) {
    int i = 0;

    // The answer will be a positive integer will be in the range [1, N+1]
    // so we try to make A[i] = i + 1 and return the integer that doesn't follow this behavior

    while (i < A.size()) {
        if (A[i] == i + 1) {
            i ++;
        } else if (A[i] >= 1 && A[i] <= A.size()) {
            if (A[i] == A[A[i] - 1]) {
                i ++;
            } else {
                swap(A[i], A[A[i] - 1]);
            }
        } else {
            i ++;
        }
    }
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] != i + 1) {
            return i + 1;
        } else continue;
    }
    return A.size() + 1;
}
