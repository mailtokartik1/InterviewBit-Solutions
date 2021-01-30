int Solution::solve(vector<int> &A) {

    // Corner case

    if (A.size() <= 0) {
        return -1;
    }

    // sort the array

    sort(A.begin(), A.end());

    // check the values

    for(int i = 0; i < A.size(); i ++) {
        int j;
        for (j = i + 1; j < A.size(); j ++) {
            if (A[i] != A[j]) {
                if (A[i] == A.size() - j) {
                    //cout << i << j;
                    return 1;
                }
                break;
            }
        }
        if (j == A.size() && A[i] == 0) {
            return 1;
        }
    }
    return -1;
}
