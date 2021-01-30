void Solution::nextPermutation(vector<int> &A) {

    // corner case

    if (A.size() <= 1) {
        return;
    }
    int i = A.size() - 1;
    int j = i - 1;
    int diff = 0;

    // Check for the next permutation

    while (j >= 0) {
        if (A[j] >= A[i]) {
            j --;
            i --;
        } else {
            int mini = INT_MAX;
            int l = -1;
            for (int k = i; k < A.size(); k ++) {
                int diff = A[k] - A[j];
                if (diff > 0 && diff < mini) {
                    mini = diff;
                    l = k;
                }
            }
            swap(A[j], A[l]);
            break;
        }
    }
    if (j == -1) {
        sort(A.begin(), A.end());
    }
    sort(A.begin() + j + 1, A.end());
    return;
}
