// Helper function to check if a value exists in an array

bool exists(vector<int> A, int val) {
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == val) {
            return 1;
        }
    }
    return false;
}
void Solution::setZeroes(vector<vector<int> > &A) {

    // Corner case

    if (A.size() <= 0 || A[0].size() <= 0) {
        return;
    }
    vector<int> B, C;

    // Store the row and columns which go zero

    for (int i = 0; i < A.size(); i ++) {
        for (int j = 0; j < A[0].size(); j ++) {
            if (A[i][j] == 0) {
                if (!exists(B, i)) {
                    B.push_back(i);
                }
                if (!exists(C, j)) {
                    C.push_back(j);
                }
            }
        }
    }

    // set rows and columns to zero

    for (int i = 0; i < B.size(); i ++) {
        for (int j = 0; j < A[0].size(); j ++) {
            A[B[i]][j] = 0;
        }
    }
    for (int i = 0; i < C.size(); i ++) {
        for (int j = 0; j < A.size(); j ++) {
            A[j][C[i]] = 0;
        }
    }
}
