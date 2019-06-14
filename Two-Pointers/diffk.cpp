int Solution::diffPossible(vector<int> &A, int B) {

    // Corner case

    if (A.size() <= 1) {
        return 0;
    }
    int i = 0;
    int j = i + 1;

    // Check for the difference by keeping both pointers at the start

    while (j < A.size() && i < A.size() && j > i) {
        if (A[j] - A[i] == B) {
            return 1;
        } else if (A[j] - A[i] > B) {
            if (j - i == 1) {
                i ++;
                j ++;
            } else {
                i ++;
            }
        } else if (A[j] - A[i] < B) {
            j ++;
        }
    }
    return 0;
}
