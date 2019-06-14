vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> B;
    int l = -1;
    int r;

    // Find the first index where A[i + 1] < A[i]

    for (int i = 0; i < A.size() - 1; i ++) {
        if (A[i + 1] < A[i]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        return vector<int>(1, -1);
    }

    // Find the first index where A[i - 1] > A[i]

    for (int i = A.size() - 1; i >= 1; i --) {
        if (A[i - 1] > A[i]) {
            r = i;
            break;
        }
    }

    // Find min and max from positions l to r

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = l; i <= r; i ++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
        if (A[i] < mini) {
            mini = A[i];
        }
    }

    // Check for left index

    for (int i = 0; i < l; i ++) {
        if (A[i] > mini) {
            l = i;
        }
    }

    // check for right index

    for (int i = A.size() - 1; i > r; i --) {
        if (A[i] < maxi) {
            r = i;
        }
    }
    B.push_back(l);
    B.push_back(r);
    return B;
}
