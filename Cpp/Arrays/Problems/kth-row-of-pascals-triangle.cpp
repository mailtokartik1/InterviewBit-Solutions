vector<int> Solution::getRow(int A) {
    vector<int> C;

    // Corner case

    if (A < 0) {
        return C;
    }

    // Resultant matrix is initialized to size A + 1

    vector<vector<int> > B(A + 1, vector<int>(1));
    for (int i = 0; i < A + 1; i ++) {
        B[i][0] = 1;
    }
    for (int i = 1; i < A + 1; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (i == j) {
                B[i].push_back(B[i - 1][j - 1]);
            } else {
                B[i].push_back(B[i - 1][j] + B[i - 1][j - 1]);
            }
        }
        
    }
    return B[A];
}
