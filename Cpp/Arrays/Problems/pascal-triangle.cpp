vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > C;

    // Corner case

    if (A <= 0) {
        return C;
    }
    vector<vector<int> > B(A);
    for (int i = 0; i < A; i ++) {
        B[i].push_back(1);
    }
    for (int i = 1; i < A; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (i == j) {
                B[i].push_back(B[i - 1][j - 1]);
            } else {
                B[i].push_back(B[i - 1][j] + B[i - 1][j - 1]);
            }
        }
    }
    return B;
}
