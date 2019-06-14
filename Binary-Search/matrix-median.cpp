int Solution::findMedian(vector<vector<int> > &A) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }
    if (A[0].size() <= 0) {
        return 0;
    }
    vector<int> B;

    // simply find the median by returning the mid element    

    for (int i = 0; i < A.size(); i ++) {
        for (int j = 0; j < A[0].size(); j ++) {
            B.push_back(A[i][j]);
        }
    }
    sort(B.begin(), B.end());
    int mid = (B.size() - 1) / 2;
    return B[mid];
}
