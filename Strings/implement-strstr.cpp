int Solution::strStr(const string A, const string B) {

    // Corner case

    if (A.size() == 0 || B.size() == 0) {
        return -1;
    }
    int start = -1, j = 0, i = 0;
    bool isCheck = false;

    // Keep one pointer in the needle and one in the hay

    while (j < B.size() && i < A.size()) {
        if (isCheck) {
            if (A[i] == B[j]) {
                j ++;
                i ++;
            } else {
                j = 0;
                i = start + 1;
                isCheck = false;
            }
        } else {
            start = i;
            isCheck = true;
        }
    }
    if (j == B.size()) {
        return start;
    }
    return -1;
}
