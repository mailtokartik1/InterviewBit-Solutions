vector<int> Solution::findPerm(const string A, int B) {
    vector<int> C;
    int low = 1;
    int high = B;

    // Add low and high alternatively for H and I respectively

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == 'I') {
            C.push_back(low);
            low ++;
        } else if (A[i] == 'D') {
            C.push_back(high);
            high --;
        }
    }
    C.push_back(low);
    return C;
}