int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }
    if (A[0].size() <= 0) {
        return 0;
    }

    // Finds which row to perform Binary Search in   

    int start = 0;
    int end = A[0].size() - 1;
    int index = 0;
    int widthIndex = A[0].size() - 1;
    for (int i = 0; i < A.size(); i ++) {
        if (B > A[i][A[i].size() - 1]) {
            index = i + 1;
        } else break;
    }
    if (index == A.size()) {
        return 0;
    }

    // Binary Search from start to end(possible values)

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[index][mid] == B) {
            return 1;
        } else if (A[index][mid] > B) {
            end = mid - 1;
        } else if (A[index][mid] < B) {
            start = mid + 1;
        }
    }
    return 0;
}

