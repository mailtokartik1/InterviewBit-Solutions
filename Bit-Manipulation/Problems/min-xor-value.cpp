int Solution::findMinXor(vector<int> &A) {

    // Corner case

    if (A.size() <= 1) {
        return 0;
    }

    // We sort the array and check adjacent items for min XOR value

    sort(A.begin(), A.end());
    int mini = INT_MAX;
    for (int i = 0; i < A.size() - 1; i ++) {
        if ((A[i] ^ A[i + 1]) < mini) {
            mini = (A[i] ^ A[i + 1]);
        }
    }
    return mini;
}
