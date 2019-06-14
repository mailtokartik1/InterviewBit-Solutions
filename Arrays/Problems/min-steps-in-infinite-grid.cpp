int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    /*
    if (A.size() == 0 || B.size() == 0) {
        return 0;
    }
    */

    // Max value of absolute difference between x and y coordinates

    int total = 0;
    for (int i = 0; i < A.size() - 1; i ++) {
        total += max(abs((A[i + 1]) - (A[i])), abs((B[i + 1]) - (B[i])));
        //cout << total << " ";
    }
    return total;
}
