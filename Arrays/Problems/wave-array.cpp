vector<int> Solution::wave(vector<int> &A) {
    vector<int> B;

    // Corner case

    if (A.size() == 0) {
        return B;
    }

    // Sort the array

    sort(A.begin(), A.end());

    if (A.size() == 1) {
        return A;
    }

    // Pick elements alternatively from the front and the back

    for (int i = 0; i < A.size(); i += 2) {
        if (i == A.size() - 1) {
            B.push_back(A[i]);
            break;
        } else {
            B.push_back(A[i + 1]);
            B.push_back(A[i]);
        }
    }
    return B;
}
