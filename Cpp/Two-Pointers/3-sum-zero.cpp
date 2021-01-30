vector<vector<int> > Solution::threeSum(vector<int> &A) {

    // Sorting is necessary at the beginning

    sort(A.begin(), A.end());
    vector<vector<int >> B;

    // Corner case

    if (A.size() <= 2) {
        return B;
    }

    // We use 3 pointers and proceed the sane way as 3-sum

    int i = 0, j = A.size() - 1, k = 1;
    for (i = 0; i < A.size() - 2; i ++) {
        k = i + 1; j = A.size() - 1;
        while (k < j) {
            if (A[i] + A[j] + A[k] == 0) {
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[k]);
                temp.push_back(A[j]);
                B.push_back(temp);
                j --;
                k ++;
            } else if (A[i] + A[j] + A[k] > 0) {
                j --;
            } else if (A[i] + A[j] + A[k] < 0) {
                k ++;
            }
        }
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    return B;
}
