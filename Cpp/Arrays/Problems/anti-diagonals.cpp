vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

    // Corner case

    if (A.size() <= 0) {
        vector<vector<int >> B;
        return B;
    }
    vector<vector<int >> B(2 * A.size() - 1);

    for (int j = 0; j < A.size(); j ++) {
        int temp = 0;
        for (int i = 0; i <= j; i ++) {
            B[j].push_back(A[i][j - temp]);
            temp ++;
        }
    }
    for (int i = 1; i < A.size(); i ++) {
        int temp = 0;
        for (int j = A.size() - 1; i <= j; j --) {
            B[i + A.size() - 1].push_back(A[i + temp][j]);
            temp ++;
        }
    }
    return B;
}
