string Solution::longestCommonPrefix(vector<string> &A) {
    int mini = INT_MAX;

    // Get minimum size in the string array

    for (int i = 0; i < A.size(); i ++) {
        if (A[i].size() < mini) {
            mini = A[i].size();
        }
    }
    string prefix;
    int j = 0;

    // Compare by looping through the array

    for (int i = 0; i < mini; i ++) {
        for (j = 0; j < A.size() - 1; j ++) {
            if (A[j + 1][i] != A[j][i]) {
                return prefix;
            }
        }
        if (j == A.size() - 1) {
            prefix.push_back(A[j][i]);
        }
    }
    return prefix;
}
