void Solution::rotate(vector<vector<int> > &A) {

    // corner case

    if (A.size() <= 0) {
        return;
    }
    for (int i = 0; i < A.size(); i ++) {
        for (int j = i; j < A.size(); j ++) {
            swap(A[i][j], A[j][i]);
        }
    }
    for (int i = 0; i < A.size(); i ++) {
        reverse(A[i].begin(), A[i].end());
    }
}
